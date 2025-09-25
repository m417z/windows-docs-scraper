# CRYPT_PROVUI_DATA structure

## Description

[The **CRYPT_PROVUI_DATA** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PROVUI_DATA** structure provides user interface (UI) data for a provider. This structure is used by the [CRYPT_PROVUI_FUNCS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provui_funcs) structure.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `dwFinalError`

Error code, if applicable.

### `pYesButtonText`

A pointer to a **null**-terminated string for the **Yes** button text. If this parameter is **NULL**, then "&Yes" is used.

### `pNoButtonText`

A pointer to a **null**-terminated string for the **No** button text. If this parameter is **NULL**, then "&No" is used.

### `pMoreInfoButtonText`

A pointer to a **null**-terminated string for the **More Info** button text. If this parameter is **NULL**, then "&More Info" is used.

### `pAdvancedLinkText`

A pointer to a **null**-terminated string for the **Advanced** button text.

### `pCopyActionText`

A pointer to a **null**-terminated string for the text used when the trust is valid and a time stamp is used. If this parameter is **NULL**, then "Do you want to install and run ""%1"" signed on %2 and distributed by:" is used.

### `pCopyActionTextNoTS`

A pointer to a **null**-terminated string for the text used when the trust is valid but a time stamp is not used. If this parameter is **NULL**, then "Do you want to install and run ""%1"" signed on an unknown date/time and distributed by:" is used.

### `pCopyActionTextNotSigned`

A pointer to a **null**-terminated string for the text used when a signature is not provided. If this parameter is **NULL**, then "Do you want to install and run ""%1""?" is used.

## See also

[CRYPT_PROVUI_FUNCS](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provui_funcs)