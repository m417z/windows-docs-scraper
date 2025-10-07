# OnLoadingDLL function

The **OnLoadingDLL** function loads the monitor DLL.

## Parameters

*hFilterBlob* \[in, out\]

A BLOB that the MCSVC uses to match a monitor with available NICs. This parameter always contains a request for an [IRTC](https://learn.microsoft.com/windows/win32/netmon2/irtc) interface, so most monitors do not need to add any entries to the BLOB. However, a custom monitor can add additional filter criteria (for example, that the MAC type must be Ethernet).

*pCreateFlags* \[in\]

The flags that indicate how the MCSVC controls the creation of a monitor. This parameter must be one of the following values:

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **MCS\_CREATE\_ONE\_PER\_NETCARD** | The MCSVC ensures that only one instance of this monitor exists for each NIC. A second instance can be created only if the first one is destroyed.<br> |
| **MCS\_CREATE\_CONFIGS\_BY\_DEFAULT** | If the monitor has a default internal configuration, the MCSVC does not require the user to configure the monitor before the instance is created.<br> |

*ppDefaultName* \[out\]

A pointer to a pointer to the address of the default name of the monitor. The MCSVC uses the default name when creating instances of the monitor.

For example, if the returned default name is "Router Monitor", the first monitor instance would be "Router Monitor 1", the second would be "RouterMonitor2, and so on. If **NULL** is returned, the MCSVC uses the name of the DLL.

*ppDescription* \[out\]

A pointer to a pointer to the address of the description of the monitor. The description is passed to the Monitor Control Tool, which uses the description to indicate to the user that the monitor exists. This parameter can return **NULL**.

*ppDefaultScript* \[out\]

A pointer to a pointer to the address of the default HTML Form script used to configure the monitor. Although the instances of the monitor can alter their own script, most monitors simply load their script once, from a file. The value of *ppDefaultScript* can be **NULL**; however, then either the monitor cannot be externally configured, or it must supply a script later. It is more efficient to supply a default script here.

*ppDefaultConfig* \[out\]

The address of the default string used to configure the monitor when it is created. This parameter can be set to **NULL**.

## Return value

If the function is successful, the return value is S\_OK; which is the same as NOERROR.

If the function is unsuccessful, the MCSVC omits the specified monitor from all its lists; after, no monitor of this type can be created.

## Remarks

The **OnLoadingDLL** function is called once by the MCSVC, when it first loads the DLL. The DLL then provides the default values that will be used by the MCSVC when creating an instance of a monitor.

The monitor must allocate all the necessary memory for the strings returned to the MCSVC. On return, the MCSVC makes copies of all the strings and will not attempt to free the returned strings.

The monitor should use BLOB helper functions to alter the filter BLOB.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

