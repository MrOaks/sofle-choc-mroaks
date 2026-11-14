# Sofle Choc - Custom QMK Firmware & Hardware

Custom QMK firmware, keymaps, and hardware manufacturing files for the **Sofle Choc** split mechanical keyboard, designed and maintained by **Mr. Oaks**.

![Sofle Choc Photo](https://i.imgur.com/MhSEAZYh.jpg)

## Features

- **Split Ergonomic Keyboard**: 58 keys (6×4+5 layout with thumb clusters).
- **Switches**: Low-profile Kailh Choc switches with hotswap sockets.
- **Controllers**: ProMicro USB-C (ATmega32u4, 5V / 16MHz) communicating via TRRS serial link.
- **Rotary Encoders**: Dual EC11 rotary encoders with aluminum knobs for volume, media control, and scrolling.
- **OLED Displays**: SSD1306 128x32 OLED screens featuring **Luna the dog** keyboard pet (WPM-reactive animations: sit, walk, run, bark on Caps Lock, sneak), Mr. Oaks custom logos, and layer indicators.
- **Per-Key RGB**: RGB Matrix powered by SK6812 Mini-E LEDs with layer-specific indicator colors.
- **Automated Cloud CI**: GitHub Actions workflow that automatically compiles `.hex` firmware binaries on every push.

> 📖 **Guía de Montaje:** Para el montaje físico, soldadura de componentes paso a paso e instrucciones de ensamblaje, consulta la [Guía de Construcción Sofle Choc](docs/build_guide_choc.md).

---

## Repository Structure

```text
sofle-choc-mroaks/
├── .github/workflows/
│   └── build.yml               # Automated cloud compilation with QMK CLI
├── keyboards/sofle_choc_mroaks/ # Keyboard hardware definitions, matrix, pins & drivers
│   ├── config.h
│   ├── rules.mk
│   ├── sofle_choc.h
│   ├── sofle_choc.c
│   ├── lib/                    # OLED fonts (font.c, glcdfont.c)
│   └── keymaps/
│       ├── mroaks/             # Main keymap (Luna the dog animation, tap dance, layer RGB)
│       ├── army/               # Productivity layout with dedicated macros
│       └── default/            # Reference layout
├── hardware/
│   ├── pcb/                    # KiCad PCB schematics, layouts, and footprint libraries
│   ├── gerbers/                # Production-ready Gerber archives (PCB & top plate)
│   ├── cnc/                    # DXF drawings and G-code for milling custom wood cases
│   └── 3d_print/               # STL 3D models (cases, foam templates, CAD models)
└── docs/
    ├── build_guide_choc.md     # Guía detallada paso a paso de ensamblaje, soldadura y puesta en marcha
    ├── keycapsConfiguration.png# Diagrama visual de referencia de teclas y distribución
    ├── logos/                  # Mr. Oaks logos (high-res and 32px OLED-ready bitmaps)
    └── pantallas-oled/         # OLED display documentation and references
```

---

## Keymaps Included

### 1. `mroaks` (Split Architecture)
Dado que el teclado Sofle es dividido, la compilación genera firmwares dedicados para cada mitad:
- **Mitad Izquierda (`mroaks_left`)**: Compila `sofle_choc_mroaks_left.hex` optimizado para la pantalla izquierda (estado de capas `_QWERTY`/`_LOWER`/`_RAISE`/`_ADJUST`, candados Num/Caps/Scroll, modificadores y registro de teclas).
- **Mitad Derecha (`mroaks_right`)**: Compila `sofle_choc_mroaks_right.hex` optimizado para la pantalla derecha (Logo personalizado Mr. Oaks, contador WPM a tiempo real y la mascota **Luna the Dog** con todas sus animaciones reactivas).
- **Unificado (`mroaks`)**: Compila `sofle_choc_mroaks.hex` con autodetección dinámica de mitad.

### 2. `army`
- Tailored productivity and macro layout (`MACRO1`, `MACRO2`).
- Spanish OLED support and custom animations.
- Optimized RGB matrix effects to conserve flash memory on ATmega32u4.

### 3. `default`
- Standard reference layout for Sofle Choc.

---

## Hardware & Cases

### PCB Design & Gerbers (`hardware/pcb/`, `hardware/gerbers/`)
- `hardware/pcb/SofleKeyboard.kicad_pcb` & `SofleKeyboard.sch`: Complete KiCad project for Sofle Choc v2.1 with Kailh Choc hotswap sockets, TRRS jack, and SK6812 RGB.
- `hardware/pcb/top_plate/`: KiCad project for manufacturing the FR4 switch top plate.
- `hardware/gerbers/gerber-choc-pcb-v2.1.zip`: Production-ready Gerber archive for JLCPCB/PCBWay (main PCB).
- `hardware/gerbers/gerber-choc-top-v2.1.1.zip`: Production-ready Gerber archive for JLCPCB/PCBWay (top plate).

### CNC Wood Cases (`hardware/cnc/`)
Contains vector files (`.dxf`) and ready-to-run toolpaths (`.gcode`) to machine solid wooden cases for both halves on a CNC router:
- `Madera2.dxf` / `Madera2.gcode`: Main top and bottom wooden body.
- `IzqDelantera.gcode`, `IzqTRasera.gcode`, `DerDelantera.gcode`, `DerTRasera.gcode`: Dedicated half toolpaths.
- Surface leveling and facing routines (`cepillado1`, `cepillado2`).

### 3D Printing (`hardware/3d_print/`)
- `Sofle Case.stl`: 3D printable case for standard builds.
- `Sofle+Choc+Case+Battery+without+3.5mm.stl`: Case designed for battery clearance and wireless setups.
- `Foam Template.stl`: Cutting template for sound dampening synthetic foam.
- 3D reference CAD snapshots of switches, keycaps, encoders, OLEDs, and ProMicro controllers.

---

## Building the Firmware

### Option A: Cloud Build (GitHub Actions)
Every `push` to `main` automatically triggers the GitHub Actions workflow in `.github/workflows/build.yml`.
1. Go to the **Actions** tab in this repository.
2. Select the latest run.
3. Download the **`sofle-choc-firmware`** artifact containing the compiled `.hex` files.

### Option B: Local Compilation with QMK CLI / MSYS
Clone this repository and compile with QMK:

```bash
# Copy keyboard definition into your local QMK firmware directory
cp -r keyboards/sofle_choc_mroaks /path/to/qmk_firmware/keyboards/

# Compile the mroaks keymap
qmk compile -kb sofle_choc_mroaks -km mroaks

# Compile the army keymap
qmk compile -kb sofle_choc_mroaks -km army
```

---

## Flashing Instructions

1. **Mitad Izquierda**:
   - Conecta la mitad izquierda del teclado a tu PC mediante USB (sin el cable TRRS conectado).
   - Pon el controlador en modo bootloader pulsando el botón de **Reset** dos veces seguidas.
   - Flashea el archivo **`sofle_choc_mroaks_left.hex`** usando **QMK Toolbox** o por línea de comandos:
     ```bash
     qmk flash -kb sofle_choc_mroaks -km mroaks_left
     ```
   - Desconecta la mitad izquierda.

2. **Mitad Derecha**:
   - Conecta la mitad derecha del teclado a tu PC mediante USB.
   - Pulsa el botón de **Reset** dos veces seguidas para entrar en modo bootloader.
   - Flashea el archivo **`sofle_choc_mroaks_right.hex`**:
     ```bash
     qmk flash -kb sofle_choc_mroaks -km mroaks_right
     ```
   - Desconecta la mitad derecha.

3. **Conexión final**:
   - Con ambos lados desconectados del USB, conecta el cable TRRS entre las dos mitades.
   - Conecta el cable USB a la mitad izquierda (maestra). Ambas mitades se encenderán mostrando el estado en la izquierda y la mascota Luna en la derecha.

---

## License

GPL v2 or later (consistent with QMK Firmware licensing).
