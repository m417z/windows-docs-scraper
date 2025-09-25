# EnableThemeDialogTexture function

## Description

Enables or disables the visual style of the background of a dialog window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Window handle of the target dialog box.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One of the following option flag values:

| Value | Meaning |
| --- | --- |
| ETDT_DISABLE | Disables background texturing. |
| ETDT_ENABLE | Enables dialog window background texturing. The texturing is defined by a visual style. |
| ETDT_USETABTEXTURE | Uses the Tab control texture for the background texture of a dialog window. |
| ETDT_USEAEROWIZARDTABTEXTURE | Uses the Aero wizard texture for the background texture of a dialog window. |
| ETDT_ENABLETAB | Enables dialog window background texturing. The texture is the Tab control texture defined by the visual style. This flag is equivalent to (ETDT_ENABLE | ETDT_USETABTEXTURE). |
| ETDT_ENABLEAEROWIZARDTAB | ETDT_ENABLE | ETDT_USEAEROWIZARDTABTEXTURE. |
| ETDT_VALIDBITS | ETDT_DISABLE | ETDT_ENABLE | ETDT_USETABTEXTURE | ETDT_USEAEROWIZARDTABTEXTURE. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**EnableThemeDialogTexture** can be used to tailor dialog box compatibility with child windows and controls that may or may not coordinate rendering their client area backgrounds with that of their parent dialog box.