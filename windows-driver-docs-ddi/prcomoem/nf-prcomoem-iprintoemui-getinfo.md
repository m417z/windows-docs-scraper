# IPrintOemUI::GetInfo

## Description

A user interface plug-in's `IPrintOemUI::GetInfo` method returns identification information.

## Parameters

### `dwMode`

Contains one of the following caller-supplied integer constants.

#### OEMGI_GETREQUESTEDHELPERINTERFACES

The method must write the bit flag value of OEMPUBLISH_IPRINTCOREHELPER to the buffer *pBuffer* if the [IPrintOemUI::PublishDriverInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-publishdriverinterface) method should be called with parameter *pIUnknown* pointing to an object that implements the [IPrintCoreHelperPS Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps) or [IPrintCoreHelperUni Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni).

#### OEMGI_GETSIGNATURE

The method must return a unique four-byte identification signature. The plug-in must also place this signature in [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures, as described in the description of the [OEMCUIPPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemcuipparam) structure's **pOEMOptItems** member.

#### OEMGI_GETVERSION

The method must return the user interface plug-in's version number as a DWORD. The version format is developer-defined.

### `pBuffer`

Caller-supplied pointer to memory allocated to receive the information specified by *dwMode*.

### `cbSize`

Caller-supplied size of the buffer pointed to by *pBuffer*.

### `pcbNeeded`

Caller-supplied pointer to a location to receive the number of bytes written into the buffer pointed to by *pBuffer*.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

User interface plug-ins are required to implement the `IPrintOemUI::GetInfo` method, which is called immediately after the plug-in is loaded. The method should return the specified information by writing it to the address specified by *pBuffer* and writing the size, in bytes, of the returned information into the location specified by *pcbNeeded*.

If *pBuffer* is **NULL**, the method should just use *pcbNeeded* to return the number of bytes required to store the specified information.

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).

## See also

[IPrintOemPS::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-getinfo)

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)

[IPrintOemUni::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getinfo)