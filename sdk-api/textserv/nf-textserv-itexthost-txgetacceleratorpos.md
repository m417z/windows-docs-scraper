# ITextHost::TxGetAcceleratorPos

## Description

Requests the special character to use for the underlining accelerator character.

## Parameters

### `pcp`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The character position of the character to underline. This variable is set by the text host. A character position of
–1 (that is, negative one) indicates that no character should be underlined.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is **S_OK**.

## Remarks

Accelerators allow keyboard shortcuts, or accelerator keys, to various UI elements (such as buttons). Typically, the shortcut character is underlined.

This method tells the text services object which character is the accelerator and thus should be underlined. Note that the text services object does
*not* process accelerators; that is the responsibility of the host.

This method is typically only called if the TXTBIT_SHOWACCELERATOR bit is set in the text services object. See [OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange).

**Note** *Any* change to the text in the text services object results in the invalidation of the accelerator underlining. In this case, it is the host's responsibility to recalculate the appropriate character position and inform the text services object that a new accelerator is available.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)