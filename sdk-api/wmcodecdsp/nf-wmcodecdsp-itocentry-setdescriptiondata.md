# ITocEntry::SetDescriptionData

## Description

The **SetDescriptionData** method associates a caller-supplied data block with the entry.

## Parameters

### `dwDescriptionDataSize` [in]

The size, in bytes, of the data block.

### `pbtDescriptionData` [in]

Pointer to the first byte of the data block.

### `pguidType` [in]

Pointer to a **GUID** that identifies the type of data in the block. This parameter can be **NULL**. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You can use this method to associate any information of your choice with the entry. The nature of the information you store in the description data block is completely up to you. TOC Parser does not inspect or interpret the description data block.

You can associate only one description data block with a given entry at a given time. However, you might want to design different types of description data blocks and identify each type of block with a globally unique identifier (GUID). That way, you could associate description data of a certain type with some of your entries and description data of a different type with other entries. If you do not need to distinguish between different types of description data blocks, you can set *pguidType* to **NULL**.

## See also

[GetDescriptionData](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-getdescriptiondata)

[ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry)