# _PEP_PPM_QUERY_LP_SETTINGS structure

## Description

The **PEP_PPM_QUERY_LP_SETTINGS** structure contains a kernel handle to the registry key that contains the power optimization settings that the platform extension plug-in (PEP) has defined for each power scenario.

## Members

### `RegistryRoot` [out]

The kernel handle to the registry root that contains the settings for a platform power scenario. For more information, see Remarks.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_LP_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_lp_settings) notification. The **RegistryRoot** member contains an output value that the PEP writes to the structure in response to this notification.

The PEP can provide settings for certain key power scenarios such as full-screen video playback and connected standby that have unique characteristics that can benefit from specially tuned power policies that are different from the default settings used by Windows. The PEP loads the settings for such a power scenario into the registry and passes the registry key for these settings to the operating system.

## See also

[PEP_NOTIFY_PPM_QUERY_LP_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_lp_settings)