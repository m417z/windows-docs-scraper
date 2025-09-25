# lineOpen function

## Description

The
**lineOpen** function opens the line device specified by its device identifier and returns a line handle for the corresponding opened line device. This line handle is used in subsequent operations on the line device.

## Parameters

### `hLineApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifies the line device to be opened. It can either be a valid device identifier or the value.

| Value | Meaning |
| --- | --- |
| **LINEMAPPER** | This value is used to open a line device in the system that supports the properties specified in *lpCallParams*. The application can use [lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid) to determine the identifier of the line device that was opened. |

### `lphLine`

Pointer to an HLINE handle that is then loaded with the handle representing the opened line device. Use this handle to identify the device when invoking other functions on the open line device.

### `dwAPIVersion`

API version number under which the application and Telephony API have agreed to operate. This number is obtained with
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion).

### `dwExtVersion`

Extension version number under which the application and the service provider agree to operate. This number is zero if the application does not use any extensions. This number is obtained with
[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion).

### `dwCallbackInstance`

User-instance data passed back to the application with each message associated with this line or with addresses or calls on this line. This parameter is not interpreted by the Telephony API.

### `dwPrivileges`

Privilege the application wants when notified of a call This parameter contains one or more of the
[LINECALLPRIVILEGE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallprivilege--constants). For applications using TAPI version 2.0 or later, values for this parameter can also be combined with one or more of the
[LINEOPENOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineopenoption--constants).

If the LINEOPENOPTION_SINGLEADDRESS option is specified, then the application is interested only in new calls that appear on the address specified by the **dwAddressID** member in the
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure pointed to by the *lpCallParams* parameter (which must be specified).

If LINEOPENOPTION_SINGLEADDRESS is specified but either *lpCallParams* is invalid or the included **dwAddressID** does not exist on the line, the open fails with LINERR_INVALADDRESSID.

In addition to setting the **dwAddressID** member of the
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure to the desired address, the application must also set **dwAddressMode** in
**LINECALLPARAMS** to LINEADDRESSMODE_ADDRESSID.

The LINEOPENOPTION_SINGLEADDRESS option affects only TAPI's assignment of initial call ownership of calls created by the service provider using a
[LINE_NEWCALL](https://learn.microsoft.com/windows/desktop/Tapi/line-newcall) message. An application that opens the line with LINECALLPRIVILEGE_MONITOR continues to receive monitoring handles to all calls created on the line. Furthermore, the application is not restricted in any way from making calls or performing other operations that affect other addresses on the opened line.

When the LINEOPENOPTION_PROXY option is specified (TAPI 2.0 or higher only), the application must also indicate which specific proxy requests it is prepared to handle. It does so by passing, in the *lpCallParams* parameter, a pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure in which the **dwDevSpecificSize** and **dwDevSpecificOffset** members have been set to delimit an array of **DWORD**s. Each element of this array shall contain one of the
[LINEPROXYREQUEST_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineproxyrequest--constants). For example, a proxy handler application that supports all five of the Agent-related functions would pass in an array of five **DWORD**s (**dwDevSpecificSize** would be 20 decimal) containing the five defined LINEPROXYREQUEST_ values.

The proxy request handler application can run on any machine that has authorization to control the line device. However, requests are always routed through the server on which the service provider is executing that actually controls the line device. Thus, it is most efficient if the application handling proxy requests (such as ACD agent control) executes directly on the server along with the service provider.

Subsequent attempts, by the same application or other applications, to open the line device and register to handle the same proxy requests as an application that is already registered fail with LINEERR_NOTREGISTERED.

To stop handling requests on the line, the application simply calls
[lineClose](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineclose).

Other flag combinations return the LINEERR_INVALPRIVSELECT error.

### `dwMediaModes`

The media type or modes of interest to the application. This parameter is used to register the application as a potential target for incoming call and call handoff for the specified media type. This parameter is meaningful only if the bit LINECALLPRIVILEGE_OWNER in *dwPrivileges* is set (and ignored otherwise). This parameter uses one or more of the
[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

### `lpCallParams`

Pointer to a structure of type
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams). This pointer is only used if LINEMAPPER or LINEOPENOPTION_PROXY is used; otherwise *lpCallParams* is ignored. It describes the call parameter that the line device should be able to provide.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_ALLOCATED, LINEERR_LINEMAPPERFAILED, LINEERR_BADDEVICEID, LINEERR_NODRIVER, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NOMEM, LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_OPERATIONFAILED, LINEERR_INVALAPPHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALMEDIAMODE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_INVALPRIVSELECT, LINEERR_REINIT, LINEERR_NODEVICE, LINEERR_OPERATIONUNAVAIL.

## Remarks

If LINEERR_ALLOCATED is returned, the line cannot be opened due to a "persistent" condition, such as that of a serial port being exclusively opened by another process. If LINEERR_RESOURCEUNAVAIL is returned, the line cannot be opened due to a dynamic resource overcommitment such as in DSP processor cycles or memory. This overcommitment can be transitory, caused by monitoring of media type or tones, and changes in these activities by other applications can make it possible to reopen the line within a short time period. If LINEERR_REINIT is returned and TAPI reinitialization has been requested (for example, as a result of adding or removing a telephony service provider), then
**lineOpen** requests are rejected with this error until the last application shuts down its usage of the API (using
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)); at that time the new configuration becomes effective and applications are once again permitted to call
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa).

Opening a line always entitles the application to make calls on any address available on the line. The ability of the application to deal with incoming calls or to be the target of call handoffs on the line is determined by the *dwMediaModes* parameter. The
**lineOpen** function registers the application as having an interest in monitoring calls or receiving ownership of calls that are of the specified media types. If the application just wants to monitor calls, then it can specify LINECALLPRIVILEGE_MONITOR. If the application just wants to make outgoing calls, it can specify LINECALLPRIVILEGE_NONE. If the application is willing to control unclassified calls (calls of unknown media type), it can specify LINECALLPRIVILEGE_OWNER and LINEMEDIAMODE_UNKNOWN. Otherwise, the application should specify the media type it is interested in handling. The application can call the [lineSetCallPrivilege](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallprivilege) function to change the call privileges specified by the LINECALLPRIVILEGES_Constants.

The media types specified with
**lineOpen** add to the default value for the provider's media type monitoring for initial incoming call type determination. The
[lineMonitorMedia](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitormedia) function modifies the mask that controls
[LINE_MONITORMEDIA](https://learn.microsoft.com/windows/desktop/Tapi/line-monitormedia) messages. If a line device is opened with owner privilege and an extension media type is not registered, then the error LINEERR_INVALMEDIAMODE is returned.

An application that has successfully opened a line device can always initiate calls using
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall),
[lineUnpark](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunpark),
[linePickup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linepickup), and
[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference) (with a **NULL***hCall*), as well as use
[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward) (assuming that doing so is allowed by the device capabilities, line state, and so on).

A single application can specify multiple flags simultaneously to handle multiple media types. Conflicts can arise if multiple applications open the same line device for the same media type. These conflicts are resolved by a priority scheme in which the user assigns relative priorities to the applications. Users can set application priorities by calling the [lineSetAppPriority](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetapppriority) function. Only the highest priority application for a given media type will ever receive ownership (unsolicited) of a call of that media type. Ownership can be received when an incoming call first arrives or when a call is handed off. The [lineHandoff](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehandoff) function is called to hand off ownership of a call to another application. If the user does not assign priorities to the application, and multiple applications open the same line device, by default, the application that called **lineOpen** first will have the highest priority.

Any application (including any lower priority application) can always acquire ownership with
[lineGetNewCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnewcalls) or
[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls). If an application opens a line for monitoring at a time that calls exist on the line,
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) messages for those existing calls are not automatically generated to the new monitoring application. The application can query the number of current calls on the line to determine how many calls exist, and, if it wants, it can call
**lineGetNewCalls** to obtain handles to these calls.

An application that handles automated voice should also select the interactive voice open mode and be assigned the lowest priority for interactive voice. The reason for this is that service providers report all voice media types as interactive voice. If media type determination is not performed by the application for the UNKNOWN media type, and no interactive voice application has opened the line device, voice calls would be unable to reach the automated voice application, and would be dropped.

The same application, or different instantiations of the same application, can open the same line multiple times with the same or different parameters.

When an application opens a line device it must specify the negotiated API version and, if it wants to use the line's extensions, it should specify the line's device-specific extension version. These version numbers should have been obtained with
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) and
[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion). Version numbering allows the mixing and matching of different application versions with different API versions and service provider versions.

LINEMAPPER allows an application to select a line indirectly—by means of the services it wants from it. When opening a line device using LINEMAPPER, the following is true: All members from beginning of the
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) data structure through **dwAddressMode** are relevant. If **dwAddressMode** is LINEADDRESSMODE_ADDRESSID it means that any address on the line is acceptable, otherwise if **dwAddressMode** is LINEADDRESSMODE_DIALABLEADDR, indicating that a specific originating address (phone number) is searched for, or if it is a provider-specific extension, then **dwOrigAddressSize**/**Offset** and the portion of the variable part they refer to are also relevant. If **dwAddressMode** is a provider-specific extension, additional information can be contained in the **dwDeviceSpecific** variably sized member.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_MONITORMEDIA](https://learn.microsoft.com/windows/desktop/Tapi/line-monitormedia)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineClose](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineclose)

[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward)

[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)

[lineGetNewCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnewcalls)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[lineMonitorMedia](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitormedia)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)

[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion)

[linePickup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linepickup)

[lineProxyMessage](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxymessage)

[lineProxyResponse](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxyresponse)

[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference)

[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)

[lineUnpark](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunpark)