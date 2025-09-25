# acmDriverAdd function

## Description

The **acmDriverAdd** function adds a driver to the list of available ACM drivers. The driver type and location are dependent on the flags used to add ACM drivers. After a driver is successfully added, the driver entry function will receive ACM driver messages.

## Parameters

### `phadid`

Pointer to the buffer that receives a handle identifying the installed driver. This handle is used to identify the driver in calls to other ACM functions.

### `hinstModule`

Handle to the instance of the module whose executable or dynamic-link library (DLL) contains the driver entry function.

### `lParam`

Driver function address or a notification window handle, depending on the *fdwAdd* flags.

### `dwPriority`

Window message to send for notification broadcasts. This parameter is used only with the ACM_DRIVERADDF_NOTIFYHWND flag. All other flags require this member to be set to zero.

### `fdwAdd`

Flags for adding ACM drivers. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_DRIVERADDF_FUNCTION | The *lParam* parameter is a driver function address conforming to the [acmDriverProc](https://learn.microsoft.com/windows/desktop/api/msacm/nc-msacm-acmdriverproc) prototype. The function may reside in either an executable or DLL file. |
| ACM_DRIVERADDF_GLOBAL | Provided for compatibility with 16-bit applications. For the Win32 API, ACM drivers added by the **acmDriverAdd** function can be used only by the application that added the driver. This is true whether or not ACM_DRIVERADDF_GLOBAL is specified. For more information, see [Adding Drivers Within an Application](https://learn.microsoft.com/windows/desktop/Multimedia/adding-drivers-within-an-application). |
| ACM_DRIVERADDF_LOCAL | The ACM automatically gives a local driver higher priority than a global driver when searching for a driver to satisfy a function call. For more information, see [Adding Drivers Within an Application](https://learn.microsoft.com/windows/desktop/Multimedia/adding-drivers-within-an-application). |
| ACM_DRIVERADDF_NAME | The *lParam* parameter is a registry value name in HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Drivers32. The value identifies a DLL that implements an ACM codec. Applications can use this flag if new registry entries are created after the application has already started using the ACM. |
| ACM_DRIVERADDF_NOTIFYHWND | The *lParam* parameter is a handle of a notification window that receives messages when changes to global driver priorities and states are made. The window message to receive is defined by the application and must be passed in *dwPriority*. The *wParam* and *lParam* parameters passed with the window message are reserved for future use and should be ignored. ACM_DRIVERADDF_GLOBAL cannot be specified in conjunction with this flag. For more information about driver priorities, see the description for the [acmDriverPriority](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverpriority) function. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate resources. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)