# _D3DDDI_ADAPTERFUNCS structure

## Description

The D3DDDI_ADAPTERFUNCS structure contains functions that the user-mode display driver can implement to communicate with a graphics adapter object.

## Members

### `pfnGetCaps`

A pointer to the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function that queries for capabilities of the graphics hardware.

### `pfnCreateDevice`

A pointer to the driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) function that creates a representation of a display device that handles a collection of rendering state.

### `pfnCloseAdapter`

A pointer to the driver's [CloseAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_closeadapter) function that releases resources for a graphics adapter object.

## Remarks

Multiple graphics adapter objects can be created for a single physical graphics adapter.

The following code example demonstrates the function declarations for the functions that the members of D3DDDI_ADAPTERFUNCS point to.

```cpp
typedef HRESULT (APIENTRY *PFND3DDDI_GETCAPS)(HANDLE hAdapter, CONST D3DDDIARG_GETCAPS*);
typedef HRESULT (APIENTRY *PFND3DDDI_CREATEDEVICE)(IN HANDLE hAdapter, IN D3DDDIARG_CREATEDEVICE*);
typedef HRESULT (APIENTRY *PFND3DDDI_CLOSEADAPTER)(IN HANDLE hAdapter);
```

## See also

[CloseAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_closeadapter)

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_openadapter)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)

[OpenAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter)