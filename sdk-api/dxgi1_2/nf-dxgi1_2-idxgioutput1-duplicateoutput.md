# IDXGIOutput1::DuplicateOutput

## Description

Creates a desktop duplication interface from the [IDXGIOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutput1) interface that represents an adapter output.

## Parameters

### `pDevice` [in]

A pointer to the Direct3D device interface that you can use to process the desktop image. This device must be created from the adapter to which the output is connected.

### `ppOutputDuplication` [out]

A pointer to a variable that receives the new [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface.

## Return value

**DuplicateOutput** returns:

* S_OK if **DuplicateOutput** successfully created the desktop duplication interface.
* E_INVALIDARG for one of the following reasons:
  + The specified device (*pDevice*) is invalid, was not created on the correct adapter, or was not created from [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) (or a later version of a DXGI factory interface that inherits from **IDXGIFactory1**).
  + The calling application is already duplicating this desktop output.
* E_ACCESSDENIED if the application does not have access privilege to the current desktop image. For example, only an application that runs at LOCAL_SYSTEM can access the secure desktop.
* DXGI_ERROR_UNSUPPORTED if the created [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface does not support the current desktop mode or scenario. For example, 8bpp and non-DWM desktop modes are not supported. If **DuplicateOutput** fails with DXGI_ERROR_UNSUPPORTED, the application can wait for system notification of desktop switches and mode changes and then call **DuplicateOutput** again after such a notification occurs. For more information, refer to [EVENT_SYSTEM_DESKTOPSWITCH](https://learn.microsoft.com/windows/desktop/WinAuto/event-constants) and mode change notification ([WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange)).
* DXGI_ERROR_NOT_CURRENTLY_AVAILABLE if DXGI reached the limit on the maximum number of concurrent duplication applications (default of four). Therefore, the calling application cannot create any desktop duplication interfaces until the other applications close.
* DXGI_ERROR_SESSION_DISCONNECTED if **DuplicateOutput** failed because the session is currently disconnected.
* Other error codes are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **DuplicateOutput** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

If an application wants to duplicate the entire desktop, it must create a desktop duplication interface on each active output on the desktop. This interface does not provide an explicit way to synchronize the timing of each output image. Instead, the application must use the time stamp of each output, and then determine how to combine the images.

For **DuplicateOutput** to succeed, you must create *pDevice* from [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) or a later version of a DXGI factory interface that inherits from **IDXGIFactory1**.

If the current mode is a stereo mode, the desktop duplication interface provides the image for the left stereo image only.

By default, only four processes can use a [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface at the same time within a single session. A process can have only one desktop duplication interface on a single desktop output; however, that process can have a desktop duplication interface for each output that is part of the desktop.

For improved performance, consider using [DuplicateOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgioutput5-duplicateoutput1).

## See also

[DuplicateOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgioutput5-duplicateoutput1)

[IDXGIOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutput1)