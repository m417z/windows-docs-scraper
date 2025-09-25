# IMetaDataDispenserEx::SetOption

## Description

Sets the specified option to a given value for the current metadata scope. The option controls how calls to the current metadata scope are handled.

## Parameters

### `optionId` [in]

 A pointer to a GUID that specifies the option to be set.

### `pValue` [in]

The value to use to set the option. The type of this value must be a variant of the specified option's type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following table lists the available GUIDs that the *optionId* parameter can point to and the corresponding valid values for the *pValue* parameter.

| GUID | Description | *pValue* Parameter |
| --- | --- | --- |
| MetaDataCheckDuplicatesFor | Controls which items are checked for duplicates. | Must be a variant of type UI4, and must contain a combination of the values of the [CorCheckDuplicatesFor](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corcheckduplicatesfor-enumeration) enumeration. |
| MetaDataRefToDefCheck | Controls which referenced items are converted to definitions. By default, the metadata engine will optimize the code by converting a referenced item to its definition if the referenced item is actually defined in the current scope. | Must be a variant of type UI4, and must contain a combination of the values of the [CorRefToDefCheck](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/correftodefcheck-enumeration) enumeration. |
| MetaDataNotificationForTokenMovement | Controls which token remaps occurring during a metadata merge generate callbacks. | Must be a variant of type UI4, and must contain a combination of the values of the [CorNotificationForTokenMovement](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/cornotificationfortokenmovement-enumeration) enumeration. |
| MetaDataSetENC | Controls the behavior of edit-and-continue (ENC). Only one mode of behavior can be set at a time. | Must be a variant of type UI4, and must contain a value of the [CorSetENC](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corsetenc-enumeration) enumeration. The value is not a bitmask. |
| MetaDataErrorIfEmitOutOfOrder | Controls which emitted-out-of-order errors generate callbacks. Emitting metadata out of order is not fatal; however, if you emit metadata in an order that is favored by the metadata engine, the metadata is more compact and therefore can be more efficiently searched. | Must be a variant of type UI4, and must contain a combination of the values of the [CorErrorIfEmitOutOfOrder](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corerrorifemitoutoforder-enumeration) enumeration. |
| MetaDataImportOption | Controls which kinds of items that were deleted during an ENC are retrieved by an enumerator. | Must be a variant of type UI4, and must contain a combination of the values of the [CorImportOptions](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corimportoptions-enumeration) enumeration. |
| MetaDataThreadSafetyOptions | Controls whether the metadata engine obtains reader/writer locks, thereby ensuring thread safety. By default, the engine assumes that access is single-threaded by the caller, so no locks are obtained. Clients are responsible for maintaining proper thread synchronization when using the metadata API. | Must be a variant of type UI4, and must contain a value of the [CorThreadSafetyOptions](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corthreadsafetyoptions-enumeration) enumeration. The value is not a bitmask. |
| MetaDataGenerateTCEAdapters | Controls whether the type library importer should generate the tightly coupled event (TCE) adapters for COM connection point containers. | Must be a variant of type BOOL. If *pValue* is set to **true**, the type library importer generates the TCE adapters. |
| MetaDataTypeLibImportNamespace | Specifies a non-default namespace for the type library that is being imported. | Must be either a null value or a variant of type BSTR. If *pValue* is a null value, the current namespace is set to null; otherwise, the current namespace is set to the string that is held in the variant's BSTR type. |
| MetaDataLinkerOptions | Controls whether the linker should generate an assembly or a .NET Framework module file. | Must be a variant of type UI4, and must contain a combination of the values of the [CorLinkerOptions](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corlinkeroptions-enumeration) enumeration. |
| MetaDataRuntimeVersion | Specifies the version of the common language runtime against which this image was built. The version is stored as a string, such as "v1.0.3705". | Must be a null value, a VT_EMPTY value, or a variant of type BSTR. If *pValue* is null, the runtime version is set to null. If *pValue* is VT_EMPTY, the version is set to a default value, which is drawn from the version of Mscorwks.dll within which the metadata code is running. Otherwise, the runtime version is set to the string that is held in the variant's BSTR type. |
| MetaDataMergerOptions | Specifies options for merging metadata. | Must be a variant of type UI4, and must contain a combination of the values of the MergeFlags enumeration, which is described in the CorHdr.h file. |

## See also

[IMetaDataDispenserEx](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenserex)