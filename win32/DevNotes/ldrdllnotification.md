# LdrDllNotification callback function

\[This function may be changed or removed from Windows without further notice.\]

A notification callback function specified with the [**LdrRegisterDllNotification**](https://learn.microsoft.com/windows/win32/devnotes/ldrregisterdllnotification) function. The loader calls this function when a DLL is first loaded.

> [!WARNING]
> It is unsafe for the notification callback to call functions in ANY other module other than itself.

## Parameters

*NotificationReason* \[in\]

The reason that the notification callback function was called. This parameter can be one of the following values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **LDR\_DLL\_NOTIFICATION\_REASON\_LOADED**

1 | The DLL was loaded. The *NotificationData* parameter points to an **LDR\_DLL\_LOADED\_NOTIFICATION\_DATA** structure. \ | | **LDR\_DLL\_NOTIFICATION\_REASON\_UNLOADED**

2 | The DLL was unloaded. The *NotificationData* parameter points to an **LDR\_DLL\_UNLOADED\_NOTIFICATION\_DATA** structure. \ |

*NotificationData* \[in\]

A pointer to a constant **LDR\_DLL\_NOTIFICATION** union that contains notification data. This union has the following definition:

``` syntax
typedef union _LDR_DLL_NOTIFICATION_DATA {
    LDR_DLL_LOADED_NOTIFICATION_DATA Loaded;
    LDR_DLL_UNLOADED_NOTIFICATION_DATA Unloaded;
} LDR_DLL_NOTIFICATION_DATA, *PLDR_DLL_NOTIFICATION_DATA;
```

The **LDR\_DLL\_LOADED\_NOTIFICATION\_DATA** structure has the following definition:

``` syntax
typedef struct _LDR_DLL_LOADED_NOTIFICATION_DATA {
    ULONG Flags;                    //Reserved.
    PCUNICODE_STRING FullDllName;   //The full path name of the DLL module.
    PCUNICODE_STRING BaseDllName;   //The base file name of the DLL module.
    PVOID DllBase;                  //A pointer to the base address for the DLL in memory.
    ULONG SizeOfImage;              //The size of the DLL image, in bytes.
} LDR_DLL_LOADED_NOTIFICATION_DATA, *PLDR_DLL_LOADED_NOTIFICATION_DATA;
```

The **LDR\_DLL\_UNLOADED\_NOTIFICATION\_DATA** structure has the following definition:

``` syntax
typedef struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA {
    ULONG Flags;                    //Reserved.
    PCUNICODE_STRING FullDllName;   //The full path name of the DLL module.
    PCUNICODE_STRING BaseDllName;   //The base file name of the DLL module.
    PVOID DllBase;                  //A pointer to the base address for the DLL in memory.
    ULONG SizeOfImage;              //The size of the DLL image, in bytes.
} LDR_DLL_UNLOADED_NOTIFICATION_DATA, *PLDR_DLL_UNLOADED_NOTIFICATION_DATA;
```

*Context* \[in, optional\]

A pointer to context data for the callback function.

## Return value

This callback function does not return a value.

## Remarks

The notification callback function is called before dynamic linking takes place.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[**LdrRegisterDllNotification**](https://learn.microsoft.com/windows/win32/devnotes/ldrregisterdllnotification)

[**LdrUnregisterDllNotification**](https://learn.microsoft.com/windows/win32/devnotes/ldrunregisterdllnotification)

