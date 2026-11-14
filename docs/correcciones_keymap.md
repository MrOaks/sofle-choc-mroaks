# Registro de Discrepancias y Correcciones en Keymap

Documento de contraste entre la disposición física real de keycaps ([`docs/keycapsConfiguration.png`](keycapsConfiguration.png)) y el código del firmware en [`keyboards/sofle_choc_mroaks/keymaps/mroaks/keymap.c`](../keyboards/sofle_choc_mroaks/keymaps/mroaks/keymap.c).

---

## 1. Discrepancias Corregidas en el Firmware

### ✅ 1. Pulgar Izquierdo: Tecla exterior (`Code`) — CORREGIDO
* **Ubicación en matriz:** `L40` (primera tecla del cluster de pulgar izquierdo, fila 77 de `keymap.c`).
* **Keycap física en foto:** **`Code`**
* **Código anterior:** `KC_SCLN` (escribía la letra `ñ` con el pulgar)
* **Código corregido:** **`KC_LCTL`** (Control izquierdo, coincidiendo con el diagrama ASCII original).

---

### ✅ 2. Pulgar Derecho: Cuarta tecla (`Ctrl`) — CORREGIDO
* **Ubicación en matriz:** `R44` (cuarta tecla del cluster de pulgar derecho, fila 77 de `keymap.c`).
* **Keycap física en foto:** **`Ctrl`**
* **Código anterior:** `KC_RGUI` (abría el menú de inicio de Windows en vez de actuar como Control)
* **Código corregido:** **`KC_RCTL`** (Control derecho).

---

### ℹ️ 3. Mano Derecha: Tecla al lado de la `P` (`| \` / `< >`)
* **Ubicación en matriz:** `R15` (fila superior de letras, extremo derecho, fila 74 de `keymap.c`).
* **Keycap física en foto:** **`| \`**
* **Código actual:** **`KC_NUBS`** (Non-US Backslash)
* **Comportamiento en Windows (ES):** Escribe los caracteres menor y mayor (**`<`** y **`>`**). Se mantiene así de forma intencionada ya que en el layout del Sofle no existe la tecla estándar al lado de la Z para escribir `<` y `>`, garantizando acceso directo a estos símbolos esenciales de programación.

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
