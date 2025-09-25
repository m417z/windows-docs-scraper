# _SRBEX_DATA structure (srb.h)

## Description

The **SRBEX_DATA** structure is the generalized format for containing extended SRB data.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the extended SRB data structure. The possible values for **Type** are one of the following.

| Value | Meaning |
| --- | --- |
| **SrbExDataTypeUnknown** | The SRB extended data type is unknown. |
| **SrbExDataTypeBidirectional** | The SRB extended data is formatted as an [SRBEX_DATA_BIDIRECTIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_bidirectional) structure. |
| **SrbExDataTypeScsiCdb16** | The SRB extended data is formatted as an [SRBEX_DATA_SCSI_CDB16](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb16) structure. |
| **SrbExDataTypeScsiCdb32** | The SRB extended data is formatted as an [SRBEX_DATA_SCSI_CDB32](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb32) structure. |
| **SrbExDataTypeScsiCdbVar** | The SRB extended data is formatted as an [SRBEX_DATA_SCSI_CDB_VAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb_var) structure. |
| **SrbExDataTypeWmi** | The SRB extended data is formatted as an [SRBEX_DATA_WMI](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_wmi) structure. |
| **SrbExDataTypePower** | The SRB extended data is formatted as an [SRBEX_DATA_POWER](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_power) structure. |
| **SrbExDataTypePnp** | The SRB extended data is formatted as an [SRBEX_DATA_PNP](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_pnp) structure. |
| **SrbExDataTypeIoInfo** | The SRB extended data is formatted as an [SRBEX_DATA_IO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_io_info) structure. |

### `Length`

Length of the SRB data, in bytes, present in the **Data** member.

### `Data`

The extended SRB data block contents.

## Remarks

The SRB extended data is present when the **SrbExDataOffset** array in the [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block) structure contains valid offset locations. A storage driver initially references a memory offset location contained in **SrbExDataOffset** as an **SRBEX_DATA** structure. A pointer to the data block is then cast to the appropriate structure type based on the data type value in the **Type** member.

The following example code fragment shows how to access the extended data for the SRB function of SRB_FUNCTION_PNP.

```cpp
BOOLEAN CheckIo( _In_ PSCSI_REQUEST_BLOCK Srb)
{
    BOOLEAN result = TRUE;
    ULONG function;
    PSTORAGE_REQUEST_BLOCK SrbEx = (PSTORAGE_REQUEST_BLOCK)Srb;
    PSRBEX_DATA SrbExData = NULL;

    function = (SrbEx->Function == SRB_FUNCTION_STORAGE_REQUEST_BLOCK) ? SrbEx->SrbFunction : Srb->Function;

    switch (function)
    {
        case SRB_FUNCTION_PNP:
        {
            STOR_PNP_ACTION PnpAction;
            BOOLEAN ForAdapter;

            if (SrbEx->Function == SRB_FUNCTION_STORAGE_REQUEST_BLOCK)
            {
                PSRBEX_DATA_PNP SrbExDataPnp = NULL;

                SrbExData = (PSRBEX_DATA) ((PUCHAR)SrbEx + SrbEx->SrbExDataOffset[0]);
                if (SrbExData->Type == SrbExDataTypePnp)
                {
                    SrbExDataPnp = (PSRBEX_DATA_PNP) SrbExData;
                    ForAdapter = (SrbExDataPnp->SrbPnPFlags == SRB_PNP_FLAGS_ADAPTER_REQUEST);
                    PnpAction = SrbExDataPnp->PnPAction;
                }
                else
                {
                    ForAdapter = FALSE;
                    result = FALSE;
                }
            }
            else
            {
                PSCSI_PNP_REQUEST_BLOCK PnpSrb = (PSCSI_PNP_REQUEST_BLOCK)Srb;

                ForAdapter = (PnpSrb->SrbPnPFlags == SRB_PNP_FLAGS_ADAPTER_REQUEST);
                PnpAction = PnpSrb->PnPAction;
           }

           if (ForAdapter)
           {
               switch (PnpAction)
               {
                   case StorRemoveDevice:
                       //
                       // ...
                       //
                       Srb->SrbStatus = SRB_STATUS_SUCCESS;
                       break;

                   default:
                       Srb->SrbStatus = SRB_STATUS_INVALID_REQUEST;
                       result = FALSE;
                       break:
            }
        }

        default:
            break;
    }

    return result;
}
```

## See also

[SRBEX_DATA_BIDIRECTIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_bidirectional)

[SRBEX_DATA_IO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_io_info)

[SRBEX_DATA_PNP](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_pnp)

[SRBEX_DATA_POWER](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_power)

[SRBEX_DATA_SCSI_CDB16](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb16)

[SRBEX_DATA_SCSI_CDB32](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb32)

[SRBEX_DATA_SCSI_CDB_VAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_scsi_cdb_var)

[SRBEX_DATA_WMI](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_wmi)