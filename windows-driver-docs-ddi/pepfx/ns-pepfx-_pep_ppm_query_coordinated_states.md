# _PEP_PPM_QUERY_COORDINATED_STATES structure (pepfx.h)

## Description

The **PEP_PPM_QUERY_COORDINATED_STATES** structure contains information about each coordinated idle state that the platform extension plug-in (PEP) supports.

## Members

### `Count` [in]

The size of the **States** array. This will be equal to the **PlatformStateCount** returned from the query platform states notification.

### `States` [out]

An array of [PEP_COORDINATED_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_coordinated_idle_state) structures that contains information about each coordinated idle state that the PEP supports.

## See also

[PEP_COORDINATED_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_coordinated_idle_state)

[PEP_NOTIFY_PPM_QUERY_COORDINATED_STATES notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states)