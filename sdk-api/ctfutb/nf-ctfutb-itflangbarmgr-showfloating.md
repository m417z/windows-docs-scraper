# ITfLangBarMgr::ShowFloating

## Description

Configures display settings for the floating language bar.

## Parameters

### `dwFlags` [in]

Specifies language bar display settings.

| Value | Meaning |
| --- | --- |
| **TF_SFT_SHOWNORMAL** | Display the language bar as a floating window. This constant cannot be combined with the TF_SFT_DOCK, TF_SFT_MINIMIZED, TF_SFT_HIDDEN, or TF_SFT_DESKBAND constants. |
| **TF_SFT_DOCK** | Deprecated as of Windows Vista. Dock the language bar in its own task pane. This constant cannot be combined with the TF_SFT_SHOWNORMAL, TF_SFT_MINIMIZED, TF_SFT_HIDDEN, or TF_SFT_DESKBAND constants. Available only on Windows XP. |
| **TF_SFT_MINIMIZED** | Deprecated as of Windows Vista. Display the language bar as a single icon in the system tray. This constant cannot be combined with the TF_SFT_SHOWNORMAL, TF_SFT_DOCK, TF_SFT_HIDDEN, or TF_SFT_DESKBAND constants. |
| **TF_SFT_HIDDEN** | Hide the language bar. This constant cannot be combined with the TF_SFT_SHOWNORMAL, TF_SFT_DOCK, TF_SFT_MINIMIZED, or TF_SFT_DESKBAND constants. |
| **TF_SFT_NOTRANSPARENCY** | Make the language bar opaque. |
| **TF_SFT_LOWTRANSPARENCY** | Make the language bar partially transparent. Available only on Windows 2000 or later. |
| **TF_SFT_HIGHTRANSPARENCY** | Make the language bar highly transparent. Available only on Windows 2000 or later. |
| **TF_SFT_LABELS** | Display text labels next to language bar icons. |
| **TF_SFT_NOLABELS** | Hide language bar icon text labels. |
| **TF_SFT_EXTRAICONSONMINIMIZED** | Display text service icons on the taskbar when the language bar is minimized. |
| **TF_SFT_NOEXTRAICONSONMINIMIZED** | Hide text service icons on the taskbar when the language bar is minimized. |
| **TF_SFT_DESKBAND** | Dock the language bar in the system task bar. This constant cannot be combined with the TF_SFT_SHOWNORMAL, TF_SFT_DOCK, TF_SFT_MINIMIZED, or TF_SFT_HIDDEN constants. Available only on Windows XP. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *dwFlags* is invalid. |

## See also

[ITfLangBarMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbarmgr)

[TF_SFT_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-sft--constants)