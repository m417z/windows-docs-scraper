# _BAND_TABLE structure

## Description

The **BAND_TABLE** structure contains the table of bands returned from an [IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_enumerate_bands) request. The bands in the band table are selected by a match condition sent as input for **IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS** in the [ENUMERATE_BANDS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_enumerate_bands_parameters) structure.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(BAND_TABLE).

### `BandTableOffset`

The offset, in bytes, to the start of an array of [BAND_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table_entry) structures.

### `BandTableEntryCount`

The number of [BAND_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table_entry) returned in the array at **BandTableOffset**.

### `BandTableEntrySize`

The size of each entry, in bytes, in the array at **BandTableOffset**. Instead of using the value of **sizeof**(BAND_TABLE_ENTRY), callers must use **BandTableEntrySize** when advancing to the next element in the band table array.

## See also

[BAND_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_table_entry)

[ENUMERATE_BANDS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_enumerate_bands_parameters)

[IOCTL_EHSTOR_BANDMGMT_ENUMERATE_BANDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_enumerate_bands)