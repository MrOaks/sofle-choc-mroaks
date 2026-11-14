# Registro de Discrepancias y Correcciones Pendientes en Keymap

Documento de contraste entre la disposición física real de keycaps ([`docs/keycapsConfiguration.png`](keycapsConfiguration.png)) y el código del firmware en [`keyboards/sofle_choc_mroaks/keymaps/mroaks/keymap.c`](../keyboards/sofle_choc_mroaks/keymaps/mroaks/keymap.c).

---

## 1. Discrepancias Críticas Identificadas

### 🔴 1. Pulgar Izquierdo: Tecla exterior (`Code`)
* **Ubicación en matriz:** `L40` (primera tecla del cluster de pulgar izquierdo, fila 77 de `keymap.c`).
* **Keycap física en foto:** **`Code`**
* **Código actual:** `KC_SCLN`
* **Comentario original en diagrama ASCII (línea 68):** `LCTRL`
* **Comportamiento en Windows (ES):** Al pulsar con el pulgar la tecla `Code`, el teclado escribe la letra **`ñ`** (o punto y coma `;`), en lugar de actuar como tecla modificadora.
* **Corrección propuesta:**
  ```c
  // Reemplazar KC_SCLN por KC_LCTL en la posición L40:
  KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_ENT, ...
  ```

---

### 🔴 2. Pulgar Derecho: Cuarta tecla (`Ctrl`)
* **Ubicación en matriz:** `R44` (cuarta tecla del cluster de pulgar derecho, fila 77 de `keymap.c`).
* **Keycap física en foto:** **`Ctrl`**
* **Código actual:** `KC_RGUI` (tecla Windows / Command derecha)
* **Comportamiento en Windows:** Al pulsar la tecla marcada como `Ctrl`, el sistema abre el menú de inicio de Windows en lugar de enviar la señal de Control.
* **Corrección propuesta:**
  ```c
  // Reemplazar KC_RGUI por KC_RCTL en la posición R44:
  ... KC_SPC, RAISE, KC_RALT, KC_RCTL, KC_DEL
  ```

---

### 🟡 3. Mano Derecha: Tecla al lado de la `P` (`| \`)
* **Ubicación en matriz:** `R15` (fila superior de letras, extremo derecho, fila 74 de `keymap.c`).
* **Keycap física en foto:** **`| \`** (Pleca / Barra vertical y Barra invertida)
* **Código actual:** `KC_NUBS` (Non-US Backslash)
* **Comportamiento en Windows (ES):** En la configuración de idioma Español (España), el código `KC_NUBS` escribe los caracteres menor y mayor (**`<`** y **`>`**).
* **Opciones de corrección:**
  * **Opción A (Mantener la función `<` y `>`):** Si conscientemente se colocó ahí la keycap `| \` para tener acceso a `<` y `>`, no se modifica el código (solo se documenta).
  * **Opción B (Comportamiento estándar español `'` y `?`):** En teclados ISO españoles, esa posición física (al lado de la P) suele llevar acentos o signos de interrogación (`KC_MINS`).
  * **Opción C (Enviar directamente `\` y `|`):** Si se desea que emita los símbolos impresos en la tecla independientemente del idioma del sistema operativo.

---

## 2. Aclaraciones de Asignación de Teclas (Coincidentes / Específicas)

### 🔵 Pulgar Izquierdo: Teclas `Meta` y `MR. OAKS`
* **`Meta` (Posición `L41`):** Asignada a `KC_LALT` (Alt izquierdo).
* **`MR. OAKS` (Posición `L42`):** Asignada a `KC_LGUI` (Tecla Windows / Super / Meta).

### 🔵 Teclas con funciones dobles (Tap Dance / Mod-Tap):
* **Shift Izquierdo (`L30`):** `TD(TD_CAPLOCK)` $\rightarrow$ 1 toque = Shift | 2 toques = Bloq Mayús (Caps Lock).
* **Shift Derecho (`R35`):** `RSFT_T(KC_ENT)` $\rightarrow$ Toque rápido = `Enter` | Mantener pulsado = `Right Shift`.
* **Puntuación `_ -` (`R34`):** `TD(TD_SLA)` $\rightarrow$ Envía `-` en pulsación simple y `_` con Shift o doble toque.
* **Acentos `¨ ´` (`R25`):** `TD(TD_COMI)` $\rightarrow$ Envía acento agudo `´` en toque simple y diéresis `¨` en doble toque o Shift.
