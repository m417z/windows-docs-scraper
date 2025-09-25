# _PEP_PPM_QUERY_STATE_NAME structure (pep_x.h)

## Description

The **PEP_PPM_QUERY_STATE_NAME** structure contains information about a specific coordinated or platform idle state.

## Members

### `StateIndex` [in]

The index of the state that the OS is querying about.

### `NameSize` [in/out]

If **Name** is **NULL**, returns the size of the buffer required to hold **Name** (including the trailing **UNICODE_NULL** character), in WCHARs.
If **Name** is not **NULL**, supplies the size of the **Name** buffer, in WCHARs.

### `Name` [in]

A pointer to a buffer to copy the name of the state to, or **NULL**.

## See also

[PEP_NOTIFY_PPM_QUERY_COORDINATED_STATE_NAME notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_NOTIFY_PPM_QUERY_PROCESSOR_STATE_NAME notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)