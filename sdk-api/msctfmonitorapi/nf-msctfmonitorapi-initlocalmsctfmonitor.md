# InitLocalMsCtfMonitor function

## Description

The **InitLocalMsCtfMonitor** function initializes TextServicesFramework on the current desktop and prepares the floating language bar, if necessary. This function must be called on the app's desktop.

## Parameters

### `dwFlags` [in]

This is a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **ILMCM_CHECKLAYOUTANDTIPENABLED** | **InitLocalMsCtfMonitor** forcefully checks the available keyboard layout or text service. If there is no secondary keyboard layout or text services, it does not initialize TextServicesFramework on the desktop. |
| **ILMCM_LANGUAGEBAROFF** | **Starting with Windows 8:** A local language bar is not started for the current desktop. |

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. |
| E_FAIL | An unspecified error occurred. |

## Remarks

If this function was successful, [UninitLocalMsCtfMonitor](https://learn.microsoft.com/windows/desktop/api/msctfmonitorapi/nf-msctfmonitorapi-uninitlocalmsctfmonitor) needs to be called before the caller thread is terminated or the desktop is switched.