# Sofle Choc - Custom QMK Firmware

Custom QMK firmware and keymaps for the **Sofle Choc** split mechanical keyboard, designed and maintained by **Mr. Oaks**.

![Sofle Choc Photo](https://i.imgur.com/MhSEAZYh.jpg)

## Features

- **Split Keyboard**: 58 keys (6×4+5 layout with thumb clusters).
- **Switches**: Low-profile Kailh Choc switches with hotswap sockets.
- **Controllers**: ProMicro (ATmega32u4, 5V / 16MHz) using serial communication over TRRS.
- **Rotary Encoders**: Dual EC11 rotary encoders for volume control, media navigation, and scrolling.
- **OLED Displays**: SSD1306 128x32 OLED screens with custom animations, WPM counter, layer indicators, and keylogger status.
- **Per-Key RGB**: RGB Matrix powered by SK6812 Mini-E LEDs.
- **Automated Cloud CI**: GitHub Actions workflow that automatically compiles `.hex` firmware files on every commit.

---

## Keymaps Included

### 1. `mroaks`
- Extended navigation and typing layers (`_QWERTY`, `_LOWER`, `_RAISE`, `_ADJUST`).
- Tap Dance keycodes for punctuation and brackets (double tap shortcuts).
- WPM-driven custom OLED animations.
- Custom encoder mappings for smooth volume and document navigation.

### 2. `army`
- Tailored productivity and macro layer layout.
- Spanish OLED support and custom animations.
- Dedicated macro shortcuts (`MACRO1`, `MACRO2`).
- Optimized RGB matrix effects to conserve flash memory on ATmega32u4.

### 3. `default`
- Standard reference layout for Sofle Choc.

---

## Building the Firmware

### Option A: Cloud Build (GitHub Actions)
Every `push` to `main` automatically triggers the GitHub Actions workflow in `.github/workflows/build.yml`.
1. Go to the **Actions** tab in this repository.
2. Select the latest run.
3. Download the **`sofle-choc-firmware`** artifact containing the compiled `.hex` files.

### Option B: Local Compilation with QMK CLI / MSYS
Clone this repository or use it as an overlay in your QMK setup:

```bash
# Set repository as overlay directory in QMK
qmk config user.overlay_dir="/path/to/sofle-choc-mroaks"

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
