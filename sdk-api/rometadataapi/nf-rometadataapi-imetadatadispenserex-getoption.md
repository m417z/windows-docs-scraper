# IMetaDataDispenserEx::GetOption

## Description

Gets the value of the specified option for the current metadata scope. The option controls how calls to the current metadata scope are handled.

## Parameters

### `optionId` [in]

A pointer to a GUID that specifies the option to be retrieved. See the Remarks section for a list of supported GUIDs.

### `pValue` [out]

The value of the returned option. The type of this value will be a variant of the specified option's type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following list shows the GUIDs that are supported for this method. For descriptions, see the [SetOption](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadatadispenserex-setoption) method. If *optionId* is not in this list, this method returns HRESULT **E_INVALIDARG**, indicating an incorrect parameter.

* MetaDataCheckDuplicatesFor
* MetaDataRefToDefCheck
* MetaDataNotificationForTokenMovement
* MetaDataSetENC
* MetaDataErrorIfEmitOutOfOrder
* MetaDataGenerateTCEAdapters
* MetaDataLinkerOptions

## See also

[IMetaDataDispenserEx](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenserex)