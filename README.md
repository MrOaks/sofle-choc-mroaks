# Sofle Choc - Custom QMK Firmware & Hardware (Mr. Oaks Edition)

Custom QMK firmware, VIA dynamic configuration, and hardware manufacturing files for the **Sofle Choc** split ergonomic mechanical keyboard, designed and maintained by **Mr. Oaks**.

![Sofle Choc Photo](https://i.imgur.com/MhSEAZYh.jpg)

---

## Hardware Specifications & Components

El **Sofle Choc Mr. Oaks Edition** es un teclado mecánico ergonómico dividido de 58 teclas con disposición *columnar stagger*, diseñado para máxima productividad y comodidad postural.

| Componente | Especificación Técnica | Detalle |
| :--- | :--- | :--- |
| **Distribución** | 58 teclas (Split 6×4 + 5 teclas por cluster de pulgar) | Ergonomía *columnar stagger* adaptada a la longitud natural de los dedos. |
| **Switches** | Kailh Choc V1 (Low Profile) | Perfil ultra-bajo con sockets **Hotswap** para reemplazo sin soldadura. |
| **Microcontroladores** | 2× ProMicro USB-C (ATmega32U4, 5V / 16MHz) | Uno en cada mitad, comunicados mediante bus serie a través de cable TRRS. |
| **Pantallas OLED** | 2× SSD1306 OLED (128×32 píxeles, conexión I2C) | **Izquierda:** Telemetría en tiempo real (capa, WPM, mods, lock states).<br>**Derecha:** Mascota animada **Ikki the Dog** reactiva a la velocidad de tecleo y logo Mr. Oaks. |
| **Encoders Rotatorios** | 2× EC11 con pulsador integrado | Diales metálicos de aluminio para control de audio, multimedia y desplazamiento. |
| **Iluminación Per-Key** | 58× LEDs RGB Matrix SK6812 Mini-E | Matriz direccionable individual con animaciones y colores inteligentes de capa. |
| **Placas y Chasis** | FR4 Switch Top Plate + Cajas de madera CNC / 3D | Archivos incluidos para fabricación en CNC (madera maciza) e impresión 3D. |
| **Configurabilidad** | Compatible con **VIA (usevia.app)** | Remapeo de teclas, capas, macros y colores en tiempo real sin flashear. |

---

## Efectos de Iluminación RGB Matrix (De Serie)

El teclado incorpora una selección curada de **6 modos de iluminación** optimizados para equilibrar espectacularidad visual y uso de memoria en el microcontrolador ATmega32U4:

1. **Color Estático (`SOLID_COLOR`)**: Todo el teclado iluminado con un color fijo personalizable en Tono (`Hue`), Saturación (`Sat`) y Brillo (`Brightness`).
2. **Alfas vs Modificadores (`ALPHAS_MODS`)**: Ilumina las teclas de letras y números en un color, y los modificadores (Shift, Ctrl, Alt, Gui, Enter...) en un tono de contraste.
3. **Respiración (`BREATHING`)**: Efecto de pulsación luminosa suave que sube y baja de intensidad de forma relajante.
4. **Ciclo Arcoíris (`CYCLE_ALL`)**: Todo el teclado va recorriendo el espectro cromático de forma gradual y al unísono.
5. **Onda Arcoíris / Wave (`CYCLE_LEFT_RIGHT`)**: El clásico efecto de ola arcoíris que fluye suavemente de izquierda a derecha a través de ambas mitades.
6. **Reactivo al Tecleo (`SOLID_REACTIVE_SIMPLE`)**: Las teclas permanecen en reposo y se encienden al ser pulsadas, desvaneciéndose suavemente tras soltarlas.

> 💡 **Indicadores Inteligentes de Capa:** Al cambiar a las capas *Lower*, *Raise* o *Adjust*, el teclado activa automáticamente el resaltado de capas: **únicamente se iluminan las teclas que tienen una función asignada en esa capa**, manteniendo apagadas las teclas transparentes/inactivas.

---

## Distribución de Capas de Fábrica (Preconfigurada en Firmware y VIA)

> [!NOTE]
> Esta es la distribución de serie incluida en el firmware y en el archivo [`sofle_choc_mroaks_layout.json`](sofle_choc_mroaks_layout.json). Gracias a **VIA**, puedes remapear cualquier tecla, mover funciones o crear macros a tu gusto en cualquier momento desde [usevia.app](https://usevia.app) sin necesidad de recompilar.

### Capa 0: Base (QWERTY ISO Español)
Disposición alfanumérica estándar en español con teclas de puntuación completas (`Ñ`, `¿`, `¡`, `<`, `>`):

```text
[ Mano Izquierda ]                                                [ Mano Derecha ]
Esc   1     2     3     4     5                                   6     7     8     9     0     Bksp
Tab   Q     W     E     R     T                                   Y     U     I     O     P     < / >
LCtl  A     S     D     F     G                                   H     J     K     L     Ñ     ' / ?
LShft Z     X     C     V     B     [Enc: Mute]     [Enc: Play]   N     M     ,     .     -     Shft/Ent
            Code  Meta  Oaks  Lower Enter           Space Raise AltGr RCtrl Del
```
* **Cluster Pulgar Izquierdo:** `Code` (`LCtl`), `Meta` (`LAlt`), `MR. OAKS` (`LGUI` / Windows), `Lower` (`MO(1)`), `Enter`.
* **Cluster Pulgar Derecho:** `Space`, `Raise` (`MO(2)`), `Alt Gr` (`RAlt`), `Ctrl` (`RCtl`), `Del`.
* **Encoders:**
  * **Izquierdo:** Giro = `Volumen + / -`, Pulsador = `Mute`.
  * **Derecho:** Giro = `Scroll / Navegación`, Pulsador = `Play/Pause`.

---

### Capa 1: `_LOWER` (Teclado Numérico / Numpad, Símbolos y Herramientas)
*Activación: Manteniendo pulsada la tecla **`Lower`** en el pulgar izquierdo.*

```text
[ Mano Izquierda - Símbolos & Herramientas ]                      [ Mano Derecha - Numpad Contable ]
`     !     @     #     $     %                                   (     7     8     9     /     Bksp
Tab   Calc  MYCM  Mail  A+PSc Alt+G                               )     4     5     6     *     =
LCtl  ¿     ?     ¡     ^     &                                   [     1     2     3     -     Del
LShft ·     ·     ·     ·     ·     [Enc: Mute]     [Enc: Play]   ]     0     ,     .     +     Enter
            LCtl  LAlt  LGUI  (TRNS) Enter          Space Raise RAlt  RCtl  Del
```
* **Mano Izquierda (Símbolos & Herramientas):**
  * **Fila Superior:** Símbolos directos (`` ` ``, `!`, `@`, `#`, `$`, `%`).
  * **Fila 1:** Herramientas de productividad (`Calc`, `MYCM` Explorador, `Mail`, `Alt+PrtScn` captura de ventana activa, `Alt+G`).
  * **Fila Central (Home Row):** Signos de puntuación en español directos (**`¿`**, **`?`**, **`¡`**) y operadores (`^`, `&`).
* **Mano Derecha (Teclado Numérico Numpad):** Bloque numérico contable completo con operadores (`/`, `*`, `-`, `+`, `=`), delimitadores (`(`, `)`, `[`, `]`), y dígitos con coma, punto y `Enter`.
* **Cluster de Pulgares:** Pulgar derecho mantiene modificadores completos (`Space`, `Raise`, `RAlt`, `RCtl`, `Del`).

---

### Capa 2: `_RAISE` (Navegación Invertida-T, Teclas F1-F12 y Sistema)
*Activación: Manteniendo pulsada la tecla **`Raise`** en el pulgar derecho.*

```text
[ Mano Izquierda - F1-F12 & Sistema ]                             [ Mano Derecha - Navegación & Símbolos ]
Esc   Power Sleep ·     ·     ·                                   Home  PgUp  PgDn  End   Del   Bksp
F1    F2    F3    F4    F5    F6                                  {     }     \     /     [     ]
F7    F8    F9    F10   F11   F12                                 ·     Home  ↑     End   ·     PgUp
LShft Calc  MYCM  Mail  A+PSc Alt+G [Enc: Mute]     [Enc: Play]   ·     ←     ↓     →     ·     PgDn
            LCtl  LAlt  LGUI  Lower Enter           Space (TRNS)RAlt  RCtl  Del
```
* **Mano Izquierda (F1-F12 & Sistema):**
  * **Fila Superior:** `Esc`, `Power` (Apagado) y `Sleep` (Suspender).
  * **Filas 1 y 2:** Botonera completa de teclas de función de **`F1` a `F12`**.
  * **Fila 3:** Atajos de productividad accesibles con una sola mano mientras el pulgar derecho sostiene `Raise`.
* **Mano Derecha (Navegación Invertida-T & Documentos):**
  * **Bloque de Flechas Invertida-T:** `↑`, `↓`, `←`, `→` con `Home`, `End`, `PgUp` y `PgDn` circundantes.
  * **Fila Superior:** Navegación rápida de documentos (`Home`, `PgUp`, `PgDn`, `End`, `Del`, `Bksp`).
  * **Fila 1:** Símbolos de programación (`{`, `}`, `\`, `/`, `[`, `]`).

---

### Capa 3: `_ADJUST` (Tri-Layer: Control Total RGB, Multimedia, Herramientas y Bootloader)
*Activación automática: Pulsando **`Lower` + `Raise`** a la vez (`MO(1) + MO(2)`).*

```text
[ Mano Izquierda - Control RGB Matrix ]                           [ Mano Derecha - Sistema & Multimedia ]
·     ·     ·     ·     ·     ·                                   ·     ·     ·     ·     ·     RESET
·     ·     ·     ·     ·     RMTgg                               Prvs  Next  Play  Mute  Vol-  Vol+
·     RMH+  RMSt+ RMVA+ RMSp+ RMMd+                               Calc  MYCM  Mail  Sleep Power ·
·     RMH-  RMSt- RMVA- RMSp- RMMd- [Enc: Mute]     [Enc: Play]   Cut   Copy  Paste Find  Undo  ·
            (TRNS)(TRNS)(TRNS)(TRNS)(TRNS)          (TRNS)(TRNS)(TRNS)(TRNS)(TRNS)
```
* **Mano Izquierda (Consola RGB Matrix):**
  * **Tecla `T`:** `RMTgg` *(Encender / Apagar la iluminación RGB Matrix)*.
  * **Fila Central (`A`, `S`, `D`, `F`, `G`):** `RMH+` *(Tono +)*, `RMSt+` *(Saturación +)*, `RM VA+` *(Brillo +)*, `RMSp+` *(Velocidad +)*, `RMMd+` *(Modo siguiente)*.
  * **Fila Inferior (`Z`, `X`, `C`, `V`, `B`):** `RMH-` *(Tono -)*, `RMSt-` *(Saturación -)*, `RM VA-` *(Brillo -)*, `RMSp-` *(Velocidad -)*, `RMMd-` *(Modo anterior)*.
* **Mano Derecha (Multimedia, Sistema y Bootloader):**
  * **Esquina Superior Derecha (Tecla `Bksp`):** **`RESET`** *(Entra directamente al modo Bootloader para flashear sin usar pinzas ni desconectar cables)*.
  * **Fila 1:** `Prvs`, `Next`, `Play`, `Mute`, `Vol -`, `Vol +`.
  * **Fila 2:** `Calc` *(Calculadora de Windows)*, `MYCM` *(Explorador de archivos)*, `Mail` *(Correo)*, `Sleep` *(Suspender)*, `Power` *(Apagar)*.
  * **Fila 3:** Atajos de edición rápida: `Cut` *(Cortar)*, `Copy` *(Copiar)*, `Paste` *(Pegar)*, `Find` *(Buscar)*, `Undo` *(Deshacer)*.

---

## Keycaps Configuration Diagram

Configuración física y keycaps montados en el teclado de referencia:

![Configuración de Keycaps - Sofle Choc Mr. Oaks](docs/keycapsConfiguration.png)

---

## Repository Structure

```text
sofle-choc-mroaks/
├── .github/workflows/
│   └── build.yml               # Automated cloud compilation with QMK CLI
├── sofle_choc_via.json         # VIA keyboard definition file (Load in usevia.app -> Design)
├── sofle_choc_mroaks_layout.json # Official layout backup (Load in usevia.app -> Save + Load)
├── keyboards/sofle_choc_mroaks/ # Keyboard hardware definitions, matrix, pins & drivers
│   ├── config.h
│   ├── rules.mk
│   ├── sofle_choc_mroaks.h
│   ├── sofle_choc_mroaks.c
│   ├── lib/                    # OLED fonts & glyphs (font.c, glcdfont.c)
│   └── keymaps/
│       ├── via/                # Official VIA keymap (via_left / via_right split targets)
│       ├── mroaks/             # Static QMK keymap (standalone alternative without VIA)
│       └── default/            # Upstream QMK reference layout
├── hardware/
│   ├── pcb/                    # KiCad PCB schematics, layouts, and footprint libraries
│   ├── gerbers/                # Production-ready Gerber archives (PCB & top plate)
│   ├── cnc/                    # DXF drawings and G-code for milling custom wood cases
│   └── 3d_print/               # STL 3D models (cases, foam templates, CAD models)
└── docs/
    ├── build_guide_choc.md     # Guía detallada paso a paso de ensamblaje y soldadura
    ├── keycapsConfiguration.png# Diagrama visual de referencia de teclas y distribución física
    └── referencias/            # Material de consulta externa y tutoriales (oled_tutorial)
```

---

## Building the Firmware

### Option A: Cloud Build (GitHub Actions - Recommended)
Cada `push` a `main` compila automáticamente el firmware en la nube:
1. Dirígete a la pestaña **Actions** en este repositorio.
2. Selecciona la ejecución más reciente.
3. Descarga el paquete **`sofle-choc-firmware`** con todos los binarios `.hex` listos para usar.

### Option B: Local Compilation with QMK CLI
```bash
# Compilar firmware VIA oficial (Recomendado)
qmk compile -kb sofle_choc_mroaks -km via_left
qmk compile -kb sofle_choc_mroaks -km via_right

# Compilar firmware estático alternativo
qmk compile -kb sofle_choc_mroaks -km mroaks_left
qmk compile -kb sofle_choc_mroaks -km mroaks_right
```

---

## Flashing Instructions

> ⚠️ **Regla de oro:** Desconecta siempre el cable USB antes de conectar o desconectar el cable TRRS entre ambas mitades.

1. **Mitad Izquierda (Master)**:
   - Conecta la mitad izquierda del teclado al PC mediante USB.
   - Pon el controlador en modo bootloader (pulsando **`Lower + Raise + Reset`** en el teclado, o con doble pulsación al botón físico de Reset).
   - Flashea el archivo **`sofle_choc_via_left.hex`** con **QMK Toolbox** o el script automatizado `flash_left.ps1` (Microcontrolador: `atmega32u4`).
   - Desconecta la mitad izquierda.

2. **Mitad Derecha (Slave con Ikki the Dog)**:
   - Conecta la mitad derecha del teclado al PC mediante USB.
   - Pulsa el botón físico de **Reset** dos veces seguidas para entrar en bootloader.
   - Flashea el archivo **`sofle_choc_via_right.hex`** con **QMK Toolbox** o el script `flash_right.ps1`.
   - Desconecta la mitad derecha.

3. **Puesta en marcha y VIA**:
   - Conecta el cable TRRS entre ambas mitades.
   - Conecta el cable USB a la mitad izquierda (maestra).
   - Abre [usevia.app](https://usevia.app) en Chrome/Edge, pulsa **Authorize device** para conectar, y en la pestaña **Save + Load** carga `sofle_choc_mroaks_layout.json` para tener toda la distribución configurada de inmediato.

---

## License

GPL v2 or later (consistent with QMK Firmware licensing).
