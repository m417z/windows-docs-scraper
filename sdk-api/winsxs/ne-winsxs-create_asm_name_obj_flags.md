# CREATE_ASM_NAME_OBJ_FLAGS enumeration

## Description

The **CREATE_ASM_NAME_OBJ_FLAGS** enumeration is used by the [CreateAssemblyNameObject](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-createassemblynameobject) function.

If no value is specified, the *szAssemblyName* parameter of the [CreateAssemblyNameObject](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-createassemblynameobject) function is the "Name" portion of the fully-specified assembly name.

## Constants

### `CANOF_PARSE_DISPLAY_NAME:0x1`

If this flag is specified, the *szAssemblyName* parameter of [CreateAssemblyNameObject](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-createassemblynameobject) is a fully-specified side-by-side assembly name and is parsed to the individual properties.

### `CANOF_SET_DEFAULT_VALUES:0x2`

Reserved.