# CreateAssemblyNameObject function

## Description

The **CreateAssemblyNameObject** function obtains an instance of the [IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname) interface.

## Parameters

### `ppAssemblyNameObj`

Pointer to a location that receives the [IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname) pointer.

### `szAssemblyName`

A pointer to a string value containing the name of a side-by-side assembly. Depending on *dwFlags*, this is a string representation of the fully-specified side-by-side assembly name or the Name portion of the assembly name. The string value can be **NULL**.

### `dwFlags`

The value of this parameter can be a combination of [CREATE_ASM_NAME_OBJ_FLAGS](https://learn.microsoft.com/windows/win32/api/winsxs/ne-winsxs-create_asm_name_obj_flags) enumeration options or 0. If the value is **CANOF_PARSE_DISPLAY_NAME**, the *szAssemblyName* parameter contains a string representation of the fully-specified side-by-side assembly name and is parsed to the individual properties. If 0, *szAssemblyName* is the Name portion of the side-by-side assembly name.

### `pvReserved`

This parameter is reserved and must be **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.