# IMFSample::SetSampleFlags

## Description

Sets flags associated with the sample.

Currently no flags are defined. Instead, metadata for samples is defined using attributes. To set attributes on a sample, use the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface, which [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) inherits. For a list of sample attributes, see [Sample Attributes](https://learn.microsoft.com/windows/desktop/medfound/sample-attributes).

## Parameters

### `dwSampleFlags` [in]

Reserved; must be zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)