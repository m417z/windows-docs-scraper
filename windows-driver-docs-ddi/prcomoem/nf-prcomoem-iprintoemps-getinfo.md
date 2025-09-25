# IPrintOemPS::GetInfo

## Description

A rendering plug-in's `IPrintOemPS::GetInfo` method returns identification information.

## Parameters

### `dwMode`

Contains one of the following caller-supplied integer constants.

#### OEMGI_GETPUBLISHERINFO

The method must indicate whether the rendering plug-in will be using "publishing mode". The *pBuffer* parameter points to a [PUBLISHERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_publisherinfo) structure, to be filled in by the method. For more information, see the following Remarks section.

#### OEMGI_GETREQUESTEDHELPERINTERFACES

The method must write the bit flag value of OEMPUBLISH_IPRINTCOREHELPER to the buffer *pBuffer* if the [IPrintOemPS::PublishDriverInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-publishdriverinterface) method should be called with parameter *pIUnknown* pointing to an object that implements the [IPrintCoreHelperPS Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps).

#### OEMGI_GETSIGNATURE

The method must return a unique four-byte identification signature. The plug-in must also place this signature in [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures, as described in the description of the [OEMCUIPPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemcuipparam). structure's **pOEMOptItems** member.

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
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

Rendering plug-ins for Pscript5 are required to implement the `IPrintOemPS::GetInfo` method, which is called immediately after the plug-in is loaded. The method should return the specified information by writing it to the address specified by *pBuffer* and writing the size, in bytes, of the returned information into the location specified by *pcbNeeded*.

If *pBuffer* is **NULL**, the method should just use *pcbNeeded* to return the number of bytes required to store the specified information.

In "publishing mode", all font information to be downloaded is placed in the job header. Each font is downloaded only once and can be used for any page, allowing the job to be page-order independent. If *dwMode* is OEMGI_GETPUBLISHERINFO but the plug-in does not support publishing mode, `IPrintOemPS::GetInfo` should return E_NOTIMPL.

For more information about creating and installing rendering plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).

## See also

[IPrintOemPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemps)

[IPrintOemUI::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-getinfo)

[IPrintOemUni::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getinfo)