# IDirect3DStateBlock9::Capture

## Description

Capture the current value of states that are included in a stateblock.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails because capture cannot be done while in record mode, the return value is D3DERR_INVALIDCALL.

## Remarks

The Capture method captures current values for states within an existing state block. It does not capture the entire state of the device. For example:

```

IDirect3DStateBlock9* pStateBlock = NULL;

pd3dDevice->BeginStateBlock();
// Add the ZENABLE state to the stateblock
pd3dDevice->SetRenderState ( D3DRS_ZENABLE, D3DZB_TRUE );
pd3dDevice->EndStateBlock ( &pStateBlock );

// Change the current value that is stored in the state block
pd3dDevice->SetRenderState ( D3DRS_ZENABLE, D3DZB_FALSE );
pStateBlock->Capture();			

pStateBlock->Release();

```

Creating an empty stateblock and calling the Capture method does nothing if no states have been set.

The Capture method will not capture information for lights that are explicitly or implicitly created after the stateblock is created.

## See also

[IDirect3DStateBlock9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dstateblock9)