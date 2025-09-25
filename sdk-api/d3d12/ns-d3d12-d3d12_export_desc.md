# D3D12_EXPORT_DESC structure

## Description

Describes an export from a state subobject such as a DXIL library or a collection state object.

## Members

### `Name`

The name to be exported. If the name refers to a function that is overloaded, a modified version of the name (e.g. encoding function parameter information in name string) can be provided to disambiguate which overload to use. The modified name for a function can be retrieved using HLSL compiler reflection.

If the *ExportToRename* field is non-null, *Name* refers to the new name to use for it when exported. In this case *Name* must be the unmodified name, whereas *ExportToRename* can be either a modified or unmodified name. A given internal name may be exported multiple times with different renames (and/or not renamed).

### `ExportToRename`

If non-null, this is the name of an export to use but then rename when exported.

#### Flags

The flags to apply to the export.

### `Flags`