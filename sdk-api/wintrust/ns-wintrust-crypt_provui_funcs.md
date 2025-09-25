# CRYPT_PROVUI_FUNCS structure

## Description

[The **CRYPT_PROVUI_FUNCS** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PROVUI_FUNCS** structure provides information about the user interface (UI) functions of a provider. This structure is used by the [CRYPT_PROVIDER_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_functions) structure.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `psUIData`

A pointer to a [CRYPT_PROVUI_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provui_data) structure.

### `pfnOnMoreInfoClick`

A pointer to the function called when the **More Info** button is clicked.

### `pfnOnMoreInfoClickDefault`

A pointer to the default function called when the **More Info** button is clicked.

### `pfnOnAdvancedClick`

A pointer to the function called when the **Advanced** button is clicked.

### `pfnOnAdvancedClickDefault`

A pointer to the default function called when the **Advanced** button is clicked.

## Remarks

The prototype for PFN_PROVUI_CALL is defined as:

```cpp
#include <windows.h>
#include <Wintrust.h>

typedef BOOL (*PFN_PROVUI_CALL)(
    IN HWND hWndSecurityDialog,
    IN struct _CRYPT_PROVIDER_DATA *pProvData
);

```

## See also

[CRYPT_PROVIDER_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_data)

[CRYPT_PROVIDER_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_functions)