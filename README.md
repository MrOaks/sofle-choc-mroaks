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
│   ├── cnc/                    # DXF drawings and G-code for milling custom wood cases
│   └── 3d_print/               # STL 3D models (cases, foam templates, CAD models)
└── docs/
    ├── logos/                  # Mr. Oaks logos (high-res and 32px OLED-ready bitmaps)
    └── pantallas-oled/         # OLED display documentation and references
```

---

## Keymaps Included

### 1. `mroaks`
- Extended layers (`_QWERTY`, `_LOWER`, `_RAISE`, `_ADJUST`).
- **Luna the Dog** OLED pet responding dynamically to WPM speed and Caps Lock state.
- Tap Dance shortcuts for punctuation, brackets, and Caps Lock.
- Dynamic RGB layer lighting (Red for Lower, Blue for Raise, Green for Adjust).

### 2. `army`
- Tailored productivity and macro layout (`MACRO1`, `MACRO2`).
- Spanish OLED support and custom animations.
- Optimized RGB matrix effects to conserve flash memory on ATmega32u4.

### 3. `default`
- Standard reference layout for Sofle Choc.

---

## Hardware & Cases

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

1. Connect the left half of the keyboard to your PC via USB.
2. Put the controller into bootloader mode by pressing the **Reset** button twice quickly.
3. Flash the generated `.hex` using **QMK Toolbox** or via CLI:
   ```bash
   qmk flash -kb sofle_choc_mroaks -km mroaks
   ```
4. Disconnect the left half, connect the right half, and repeat steps 2 and 3.
5. Reconnect via TRRS cable (always connect/disconnect TRRS while unplugged from USB).

---

## License

GPL v2 or later (consistent with QMK Firmware licensing).
