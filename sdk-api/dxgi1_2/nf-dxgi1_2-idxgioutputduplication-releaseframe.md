# IDXGIOutputDuplication::ReleaseFrame

## Description

Indicates that the application finished processing the frame.

## Return value

**ReleaseFrame** returns:

* S_OK if it successfully completed.
* DXGI_ERROR_INVALID_CALL if the application already released the frame.
* DXGI_ERROR_ACCESS_LOST if the desktop duplication interface is invalid. The desktop duplication interface typically becomes invalid when a different type of image is displayed on the desktop. Examples of this situation are:
  + Desktop switch
  + Mode change
  + Switch from DWM on, DWM off, or other full-screen applicationIn this situation, the application must release the [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface and create a new **IDXGIOutputDuplication** for the new content.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

The application must release the frame before it acquires the next frame. After the frame is released, the surface that contains the desktop bitmap becomes invalid; you will not be able to use the surface in a DirectX graphics operation.

For performance reasons, we recommend that you release the frame just before you call the [IDXGIOutputDuplication::AcquireNextFrame](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-acquirenextframe) method to acquire the next frame. When the client does not own the frame, the operating system copies all desktop updates to the surface. This can result in wasted GPU cycles if the operating system updates the same region for each frame that occurs. When the client acquires the frame, the client is aware of only the final update to this region; therefore, any overlapping updates during previous frames are wasted. When the client acquires a frame, the client owns the surface; therefore, the operating system can track only the updated regions and cannot copy desktop updates to the surface. Because of this behavior, we recommend that you minimize the time between the call to release the current frame and the call to acquire the next frame.

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)