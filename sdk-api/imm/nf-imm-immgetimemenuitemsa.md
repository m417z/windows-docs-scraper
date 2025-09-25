## Description

Retrieves the menu items that are registered in the IME menu of a specified input context.

## Parameters

### `unnamedParam1` [in]

Handle to the input context for the specified menu items.

### `unnamedParam2` [in]

Flag specifying menu information options. The following value is defined.

| Value | Meaning |
| --- | --- |
| **IGIMIF_RIGHTMENU** | Retrieve the menu items for the context menu, obtained by a right mouse click. |

### `unnamedParam3` [in]

Type of menu to retrieve. This parameter can have one or more of the following values.

| Value | Meaning |
| --- | --- |
| **IGIMII_CMODE** | Retrieve the menu items that control conversion mode. |
| **IGIMII_SMODE** | Retrieve the menu items that control sentence mode. |
| **IGIMII_CONFIGURE** | Retrieve the menu items that are related to IME configuration. |
| **IGIMII_TOOLS** | Retrieve the menu items that are related to IME tools. |
| **IGIMII_HELP** | Retrieve the menu items that control IME Help. |
| **IGIMII_OTHER** | Retrieve the menu items that control other IME functions. |
| **IGIMII_INPUTTOOLS** | Retrieve the menu items that control menu items related to IME input tools providing an extended way to input characters. |

### `lpImeParentMenu` [out, optional]

Pointer to an [IMEMENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-imemenuiteminfoa) structure in which the function retrieves parent menu information. To retrieve information about the submenu items of this parent menu, the application sets the **fType** member to MFT_SUBMENU. This parameter contains **NULL** if the function retrieves only top-level menu items.

### `lpImeMenu` [out, optional]

Pointer to an array of [IMEMENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-imemenuiteminfoa) structures in which the function retrieves information about the menu items. This parameter contains **NULL** if the function retrieves the number of registered menu items.

### `dwSize` [in]

Size of the buffer to receive the [IMEMENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-imemenuiteminfoa) structure.

## Return value

Returns the number of menu items copied into *lpImeMenu*. If *lpImeMenu* specifies **NULL**, the function returns the number of registered menu items in the specified input context.

## See also

[IMEMENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-imemenuiteminfoa)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

## Remarks

> [!NOTE]
> The imm.h header defines ImmGetImeMenuItems as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).