# DirectDrawCreateClipper function

## Description

Creates an instance of a DirectDrawClipper object that is not associated with a DirectDraw object.

## Parameters

### `dwFlags` [in]

Currently not used and must be set to 0.

### `lplpDDClipper` [out]

Address of a pointer to be filled with the address of the new DirectDrawClipper object.

### `pUnkOuter` [in]

Allows for future compatibility with COM aggregation features. Currently, this function returns an error if this parameter is not NULL.

## Return value

If the function succeeds, the return value is DD_OK.

If it fails, the function can return one of the following error values:

* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY

## Remarks

You can call **DirectDrawCreateClipper** before any DirectDraw objects are created. Because these DirectDrawClipper objects are not owned by any DirectDraw object, they are not automatically released when an application's objects are released. If the application does not explicitly release the DirectDrawClipper objects, DirectDraw releases them when the application terminates.

To create a DirectDrawClipper object that is owned by a specific DirectDraw object, use the [IDirectDraw7::CreateClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-createclipper) method.

You must use [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) to explicitly link to Ddraw.dll and then use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access the **DirectDrawCreateClipper** function.