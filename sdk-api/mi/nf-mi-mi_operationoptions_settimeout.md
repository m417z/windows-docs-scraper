# MI_OperationOptions_SetTimeout function

## Description

Sets the operation timeout for a specific operation.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `timeout` [in]

A pointer to the new operation timeout value.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This timeout can be set in the destination options by calling the [MI_DestinationOptions_SetTimeout](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_settimeout) function. However, sometimes one operation may take longer than others. Therefore, it is best to set a reasonable default for all operations, then use this function to override specific operations that may take longer.

If the client is asking for progress, and the provider is reporting progress, the timeout interval will be restarted after each progress report. For enumerations/subscribe/association, the interval is the maximum length before objects are delivered before it times out (subject to the progress comment).

If a client performs an operation (such as an invoke) on a [CIM](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/gloss-c) session over Windows Remote Management, the operation can take longer than the operation timeout value if the target server is unreachable (for example, because of server outage, network outage, or an unexpected firewall exception). This excessive wait time occurs because the operation may be divided into suboperations for fetching schema information from the server, and the client continues the operation even if one or more of the schema fetch suboperations has been blocked by an unreachable server.

To mitigate this issue and get the client to report the results without an excessive wait time, try one or both of these steps:

* Set the WinRM network delay time to a very low value by invoking the following command:
  **winrm set winrm/config/client @{NetworkDelayms="***DesiredValue***"}** where *DesiredValue* is the network delay value, in milliseconds. The lowest network delay that can be specified is 500 milliseconds.

  The network delay value helps to account for network latency while reaching the target machine. If you set tiny network delay and operation timeout values, however, you might not be able to communicate with a target machine that takes a long time to reach. Also, a change in the network delay value affects the entire machine, not just one operation.
* When starting the operation (calling a function with an "MI_Session_" prefix), specify the **MI_OPERATIONFLAGS_STANDARD_RTTI** flag in the *flags* parameter.

  This changes the operation behavior so that if a fetch schema suboperation fails, the operation is aborted and completes immediately instead of waiting for subsequent fetch schema suboperations to finish. Therefore, if the server was always unreachable when the operation started, the amount of time taken by the operation to complete will be equal to the sum of the operation timeout value and the WinRM network delay value.

## See also

[MI_DestinationOptions_SetTimeout](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_settimeout)

[MI_OperationOptions_GetTimeout](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_gettimeout)

[Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal)