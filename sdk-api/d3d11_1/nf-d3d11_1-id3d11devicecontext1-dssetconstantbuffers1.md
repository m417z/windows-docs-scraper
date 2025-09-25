# ID3D11DeviceContext1::DSSetConstantBuffers1

## Description

Sets the constant buffers that the domain-shader stage uses.

## Parameters

### `StartSlot` [in]

Index into the zero-based array to begin setting constant buffers to (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1).

### `NumBuffers` [in]

Number of buffers to set (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - *StartSlot*).

### `ppConstantBuffers` [in, optional]

Array of constant buffers being given to the device.

### `pFirstConstant` [in, optional]

An array that holds the offsets into the buffers that *ppConstantBuffers* specifies. Each offset specifies where, from the shader's point of view, each constant buffer starts. Each offset is measured in shader constants, which are 16 bytes (4*32-bit components). Therefore, an offset of 16 indicates that the start of the associated constant buffer is 256 bytes into the constant buffer. Each offset must be a multiple of 16 constants.

### `pNumConstants` [in, optional]

An array that holds the numbers of constants in the buffers that *ppConstantBuffers* specifies. Each number specifies the number of constants that are contained in the constant buffer that the shader uses. Each number of constants starts from its respective offset that is specified in the *pFirstConstant* array. Each number of constants must be a multiple of 16 constants, in the range [0..4096].

## Remarks

The runtime drops the call to **DSSetConstantBuffers1** if the number of constants to which *pNumConstants* points is larger than the maximum constant buffer size that is supported by shaders (4096 constants). The values in the elements of the *pFirstConstant* and *pFirstConstant* + *pNumConstants* arrays can exceed the length of each buffer; from the shader's point of view, the constant buffer is the intersection of the actual memory allocation for the buffer and the window [value in an element of *pFirstConstant*, value in an element of *pFirstConstant* + value in an element of *pNumConstants*]. The runtime also drops the call to **DSSetConstantBuffers1** on existing drivers that don't support this offsetting.

The runtime will emulate this feature for [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3; therefore, this feature is supported for feature level 9.1, 9.2, and 9.3. This feature is always available on new drivers for feature level 10 and higher.

From the shader’s point of view, element [0] in the constant buffers array is the constant at *pFirstConstant*.

Out of bounds access to the constant buffers from the shader to the range that is defined by *pFirstConstant* and *pNumConstants* returns 0.

If *pFirstConstant* and *pNumConstants* arrays are **NULL**, you get the same result as if you were binding the entire buffer into view. You get this same result if you call the [DSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dssetconstantbuffers) method. If the buffer is larger than the maximum constant buffer size that is supported by shaders (4096 elements), the shader can access only the first 4096 constants.

If either *pFirstConstant* or *pNumConstants* is **NULL**, the other parameter must also be **NULL**.

### Calling DSSetConstantBuffers1 with command list emulation

The runtime's [command list](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-command-list) emulation of **DSSetConstantBuffers1** sometimes doesn't actually change the offsets or sizes for the arrays of constant buffers. This behavior occurs when

**DSSetConstantBuffers1** doesn't effectively change the constant buffers at the beginning and end of the range of slots that you set to update. This section shows how to work around this

behavior.

Here is the code to check whether either the runtime emulates command lists or the driver supports command lists:

```cpp

     HRESULT hr = S_OK;
     bool needWorkaround = false;
     D3D11_DEVICE_CONTEXT_TYPE contextType = pDeviceContext->GetType();

     if( D3D11_DEVICE_CONTEXT_DEFERRED == contextType)
     {
          D3D11_FEATURE_DATA_THREADING threadingCaps = { FALSE, FALSE };

          hr = pDevice->CheckFeatureSupport( D3D11_FEATURE_THREADING, &threadingCaps, sizeof(threadingCaps) );
          if( SUCCEEDED(hr) && !threadingCaps.DriverCommandLists )
          {
               needWorkaround = true; // the runtime emulates command lists.
          }
     }

```

If the runtime emulates command lists, you need to use one of these code snippets:

If you change the offset and size on only a single constant buffer, set the constant buffer to **NULL** first:

```cpp

     pDeviceContext->DSSetConstantBuffers1(0, 1, &CBuf, &Offset, &Count);
     if( needWorkaround )
     {
          // Workaround for command list emulation
          pDeviceContext->DSSetConstantBuffers(0, 1, &NullCBuf);
     }
     pDeviceContext->DSSetConstantBuffers1(0, 1, &CBuf, &Offset, &Count);

```

If you change multiple constant buffers, set the first and last constant buffers of the range to **NULL** first:

```cpp

     pDeviceContext->DSSetConstantBuffers1(0, 4, &CBufs, &Offsets, &Counts);
     if( needWorkaround )
     {
          // Workaround for command list emulation
          pDeviceContext->DSSetConstantBuffers(0, 1, &NullCBuf);
          pDeviceContext->DSSetConstantBuffers(3, 1, &NullCBuf);
     }
     pDeviceContext->DSSetConstantBuffers1(0, 4, &CBufs, &Offsets, &Counts);

```

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)