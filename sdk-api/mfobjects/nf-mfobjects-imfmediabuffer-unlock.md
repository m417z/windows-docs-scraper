# IMFMediaBuffer::Unlock

## Description

Unlocks a buffer that was previously locked. Call this method once for every call to [IMFMediaBuffer::Lock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-lock).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **D3DERR_INVALIDCALL** | For Direct3D surface buffers, an error occurred when unlocking the surface. |

## Remarks

It is an error to call **Unlock** if you did not call [Lock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-lock) previously.

After calling this method, do not use the pointer returned by the [Lock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-lock) method. It is no longer guaranteed to be valid.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)