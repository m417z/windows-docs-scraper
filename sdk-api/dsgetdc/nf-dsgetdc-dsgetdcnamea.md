# DsGetDcNameA function

## Description

The **DsGetDcName** function returns the name of a
domain controller in a specified domain. This function accepts additional domain controller selection
criteria to indicate preference for a domain controller with particular characteristics.

## Parameters

### `ComputerName` [in]

Pointer to a null-terminated string that specifies the name of the server to process this function.
Typically, this parameter is **NULL**, which indicates that the local computer is
used.

### `DomainName` [in]

Pointer to a null-terminated string that specifies the name of the domain or application partition to
query. This name can either be a DNS style name, for example, fabrikam.com, or a flat-style name, for example,
Fabrikam. If a DNS style name is specified, the name may be specified with or without a trailing period.

If the *Flags* parameter contains the **DS_GC_SERVER_REQUIRED**
flag, *DomainName* must be the name of the forest. In this case,
**DsGetDcName** fails if *DomainName*
specifies a name that is not the forest root.

If the *Flags* parameter contains
the **DS_GC_SERVER_REQUIRED** flag and *DomainName* is
**NULL**, **DsGetDcName** attempts to
find a global catalog in the forest of the computer identified by *ComputerName*, which
is the local computer if *ComputerName* is **NULL**.

If *DomainName* is **NULL** and the
*Flags* parameter does not contain the **DS_GC_SERVER_REQUIRED**
flag, *ComputerName* is set to the default domain name of the primary domain of the
computer identified by *ComputerName*.

### `DomainGuid` [in]

Pointer to a [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that specifies the
**GUID** of the domain queried. If *DomainGuid* is not
**NULL** and the domain specified by *DomainName* or
*ComputerName* cannot be found,
**DsGetDcName** attempts to locate a domain controller in the
domain having the GUID specified by *DomainGuid*.

### `SiteName` [in]

Pointer to a null-terminated string that specifies the name of the site where the returned domain
controller should physically exist. If this parameter is **NULL**,
**DsGetDcName** attempts to return a domain controller in the
site closest to the site of the computer specified by *ComputerName*. This parameter
should be **NULL**, by default.

### `Flags` [in]

Contains a set of flags that provide additional data used to process the request. This parameter can be a
combination of the following values.

#### DS_AVOID_SELF

When called from a domain controller, specifies that the returned domain controller name should not be
the current computer. If the current computer is not a domain controller, this flag is ignored. This flag can
be used to obtain the name of another domain controller in the domain.

#### DS_BACKGROUND_ONLY

If the **DS_FORCE_REDISCOVERY** flag is not specified, this function uses cached
domain controller data. If the cached data is more than 15 minutes old, the cache is refreshed by pinging the
domain controller. If this flag is specified, this refresh is avoided even if the cached data is expired.
This flag should be used if the **DsGetDcName** function is
called periodically.

#### DS_DIRECTORY_SERVICE_PREFERRED

**DsGetDcName** attempts to find a domain controller that
supports directory service functions. If a domain controller that supports directory services is not
available, **DsGetDcName** returns the name of a
non-directory service domain controller. However,
**DsGetDcName** only returns a non-directory service domain
controller after the attempt to find a directory service domain controller times out.

#### DS_DIRECTORY_SERVICE_REQUIRED

Requires that the returned domain controller support directory services.

#### DS_DIRECTORY_SERVICE_6_REQUIRED

Requires that the returned domain controller be running Windows Server 2008 or later.

#### DS_DIRECTORY_SERVICE_8_REQUIRED

Requires that the returned domain controller be running Windows Server 2012 or later.

#### DS_FORCE_REDISCOVERY

Forces cached domain controller data to be ignored. When the **DS_FORCE_REDISCOVERY**
flag is not specified, **DsGetDcName** may return cached
domain controller data. If this flag is specified,
**DsGetDcName** will not use cached information (if any
exists) but will instead perform a fresh domain controller discovery.

This flag should not be used under normal conditions, as using the cached domain controller information has
better performance characteristics and helps to ensure that the same domain controller is used consistently
by all applications. This flag should be used only after the application determines that the domain
controller returned by **DsGetDcName** (when called without
this flag) is not accessible. In that case, the application should repeat the
**DsGetDcName** call with this flag to ensure that the
unuseful cached information (if any) is ignored and a reachable domain controller is discovered.

#### DS_GC_SERVER_REQUIRED

Requires that the returned domain controller be a global catalog server for the forest of domains with
this domain as the root. If this flag is set and the *DomainName* parameter is not
**NULL**, *DomainName* must specify a forest name. This flag
cannot be combined with the **DS_PDC_REQUIRED** or
**DS_KDC_REQUIRED** flags.

#### DS_GOOD_TIMESERV_PREFERRED

**DsGetDcName** attempts to find a domain controller that is
a reliable time server. The Windows Time Service can be configured to declare one or more domain controllers
as a reliable time server. For more information, see the
[Windows Time Service](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc773061(v=ws.10)) documentation. This
flag is intended to be used only by the Windows Time Service.

#### DS_IP_REQUIRED

This parameter indicates that the domain controller must have an IP address. In that case,
**DsGetDcName** will place the Internet protocol address of
the domain controller in the **DomainControllerAddress** member of
*DomainControllerInfo*.

#### DS_IS_DNS_NAME

Specifies that the *DomainName* parameter is a DNS name. This flag cannot be
combined with the **DS_IS_FLAT_NAME** flag.

Specify either **DS_IS_DNS_NAME** or **DS_IS_FLAT_NAME**. If
neither flag is specified, **DsGetDcName** may take longer
to find a domain controller because it may have to search for both the DNS-style and flat name.

#### DS_IS_FLAT_NAME

Specifies that the *DomainName* parameter is a flat name. This flag cannot be
combined with the **DS_IS_DNS_NAME** flag.

#### DS_KDC_REQUIRED

Requires that the returned domain controller be currently running the Kerberos Key Distribution Center
service. This flag cannot be combined with the **DS_PDC_REQUIRED** or
**DS_GC_SERVER_REQUIRED** flags.

#### DS_ONLY_LDAP_NEEDED

Specifies that the server returned is an LDAP server. The server returned is not necessarily a domain
controller. No other services are implied to be present at the server. The server returned does not
necessarily have a writable **config** container nor a writable
**schema** container. The server returned may not necessarily be used to create or
modify security principles. This flag may be used with the **DS_GC_SERVER_REQUIRED**
flag to return an LDAP server that also hosts a global catalog server. The returned global catalog server is
not necessarily a domain controller. No other services are implied to be present at the server. If this flag
is specified, the **DS_PDC_REQUIRED**, **DS_TIMESERV_REQUIRED**,
**DS_GOOD_TIMESERV_PREFERRED**,
**DS_DIRECTORY_SERVICES_PREFERED**,
**DS_DIRECTORY_SERVICES_REQUIRED**, and **DS_KDC_REQUIRED** flags
are ignored.

#### DS_PDC_REQUIRED

Requires that the returned domain controller be the primary domain controller for the domain. This flag
cannot be combined with the **DS_KDC_REQUIRED** or
**DS_GC_SERVER_REQUIRED** flags.

#### DS_RETURN_DNS_NAME

Specifies that the names returned in the **DomainControllerName** and
**DomainName** members of *DomainControllerInfo* should be DNS
names. If a DNS name is not available, an error is returned. This flag cannot be specified with the
**DS_RETURN_FLAT_NAME** flag. This flag implies the
**DS_IP_REQUIRED** flag.

#### DS_RETURN_FLAT_NAME

Specifies that the names returned in the **DomainControllerName** and
**DomainName** members of *DomainControllerInfo* should be
flat names. If a flat name is not available, an error is returned. This flag cannot be specified with the
**DS_RETURN_DNS_NAME** flag.

#### DS_TIMESERV_REQUIRED

Requires that the returned domain controller be currently running the Windows Time Service.

#### DS_TRY_NEXTCLOSEST_SITE

When this flag is specified, **DsGetDcName** attempts to
find a domain controller in the same site as the caller. If no such domain controller is found, it will find
a domain controller that can provide topology information and call
[DsBindToISTG](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindtoistga) to obtain a bind handle, then call
[DsQuerySitesByCost](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesbycosta) over UDP to determine the
"next closest site," and finally cache the name of the site found. If no domain controller is found in that
site, then **DsGetDcName** falls back on the default method
of locating a domain controller.

If this flag is used in conjunction with a non-NULL value in the input parameter
*SiteName*, then **ERROR_INVALID_FLAGS** is thrown.

Also, the kind of search employed with **DS_TRY_NEXT_CLOSEST_SITE** is site-specific,
so this flag is ignored if it is used in conjunction with **DS_PDC_REQUIRED**. Finally,
**DS_TRY_NEXTCLOSEST_SITE** is ignored when used in conjunction with
**DS_RETURN_FLAT_NAME** because that uses NetBIOS to resolve the name, but the domain
of the domain controller found won't necessarily match the domain to which the client is joined.

**Note** This flag is Group Policy enabled. If you enable the "Next Closest Site" policy setting, Next Closest
Site DC Location will be turned on for the machine across all available but un-configured network adapters.
If you disable the policy setting, Next Closest Site DC Location will not be used by default for the machine
across all available but un-configured network adapters. However, if a DC Locator call is made using the
**DS_TRY_NEXTCLOSEST_SITE** flag explicitly,
**DsGetDcName** honors the Next Closest Site behavior. If
you do not configure this policy setting, Next Closest Site DC Location will be not be used by default for
the machine across all available but un-configured network adapters. If the
**DS_TRY_NEXTCLOSEST_SITE** flag is used explicitly, the Next Closest Site behavior
will be used.

#### DS_WRITABLE_REQUIRED

Requires that the returned domain controller be writable; that is, host a writable copy of the directory
service.

#### DS_WEB_SERVICE_REQUIRED

Requires that the returned domain controller be currently running the Active Directory web service.

### `DomainControllerInfo` [out]

Pointer to a **PDOMAIN_CONTROLLER_INFO** value that receives a pointer to a
[DOMAIN_CONTROLLER_INFO](https://learn.microsoft.com/windows/desktop/api/dsgetdc/ns-dsgetdc-domain_controller_infoa) structure that contains
data about the domain controller selected. This structure is allocated by
**DsGetDcName**. The caller must free the structure using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function when it is no longer
required.

## Return value

If the function returns domain controller data, the return value is
**ERROR_SUCCESS**.

If the function fails, the return value can be one of the following error codes.

## Remarks

The **DsGetDcName** function is sent to the Netlogon service
on the remote computer specified by *ComputerName*. If
*ComputerName* is **NULL**, the function is processed on the local
computer.

**DsGetDcName** does not verify that the domain controller name
returned is the name of an actual domain controller or global catalog. If mutual authentication is required, the
caller must perform the authentication.

**DsGetDcName** does not require any particular access to the
specified domain. By default, this function does not ensure that the returned domain controller is currently
available. Instead, the caller should attempt to use the returned domain controller. If the domain controller is
not available, the caller should call the **DsGetDcName**
function again, specifying the **DS_FORCE_REDISCOVERY** flag.

### Response Time

When using **DsGetDcName** be aware of the following timing
details:

* **DsGetDcName** makes network calls and can take from a few
  seconds up to one minute, depending on network traffic, topology, DC load, and so on.
* It is NOT recommended to call **DsGetDcName** from a UI or
  other timing critical thread.
* The DC Locator does use optimized logic to provide the DC information as quickly as possible. It also uses
  cached information at the site to contact the closest DC.

### Notes on Domain Controller Stickiness

In Active Directory Domain Services, the domain controller locator function is designed so that once a client
finds a preferred domain controller, the client will not look for another unless that domain controller stops
responding or the client is restarted. This is referred to as "Domain Controller Stickiness." Because
workstations typically operate for months without a problem or restart, one unintended consequence of this
behavior is that if a particular domain controller goes down for maintenance, all of the clients that were
connected to it shift their connections to another domain controller. But when the domain controller comes back
up, no clients ever reconnect to it because the clients do not restart very often. This can cause
load-balancing problems.

Previously, the most common solution to this problem was to deploy a script on each client machine that
periodically called **DsGetDcName** using the
`DS_FORCE_REDISCOVERY` flag. This was a somewhat cumbersome solution, so
Windows Server 2008 and Windows Vista introduced a new mechanism that caused issues with domain
controller stickiness.

Whenever **DsGetDcName** retrieves a domain controller name
from its cache, it checks to see if this cached entry is expired, and if so, discards that domain controller
name and tries to rediscover a domain controller name. The life span of a cached entry is controlled by the
value in the following registry keys

**HKEY_LOCAL_MACHINE**\**SYSTEM**\**CurrentControlSet**\**Services**\**Netlogon**\**Parameters**\**ForceRediscoveryInterval**

and

**HKEY_LOCAL_MACHINE**\**Software**\**Policies**\**Microsoft**\**Netlogon**\**Parameters**\**ForceRediscoveryInterval**

The values in these registry keys are of type **REG_DWORD**. They specify the length in
seconds before **DsGetDcName** should try to rediscover the
domain controller name. The default value is 43200 seconds (12 hours). If the value of the
**ForceRediscoveryInterval** registry entry is set to 0, the client always
performs rediscovery. If the value is set to 4294967295, the cache never expires, and the cached domain controller
continues to be used. We recommend that you do not set the
**ForceRediscoveryInterval** registry entry to a value that is less than 3600 seconds
(60 minutes).

**Note** The registry settings of **ForceRediscoveryInterval** are group policy
enabled. If you disable the policy setting, Force Rediscovery will used by default for the machine at every 12
hour interval. If you do not configure this policy setting, Force Rediscovery will used by default for the machine
at every 12 hour interval, unless the local machine setting in the registry is a different value.

Note that if the **DS_BACKGROUND_ONLY** flag is specified,
**DsGetDcName** will never try to rediscover the domain
controller name, since the point of that flag is to force
**DsGetDcName** to use the cached domain controller name even
if it is expired.

### ETW Tracing in DsGetDcName

To turn on [ETW Tracing](https://learn.microsoft.com/windows-hardware/drivers/hid/event-tracing) for
**DsGetDcName**, create the following registry key:

**HKEY_LOCAL_MACHINE**\**System**\**CurrentControlSet**\**Services**\**DCLocator**\**Tracing**

The key will have a structure as follows:

```cpp
String ProcessName
  DWORD  PID <optional>
```

*ProcessName* must be the full name including extension of the process that you want
to get trace information for. *PID* is only required when multiple processes with the
same name exist. If it is defined, then only the process with that PID will be enabled for tracing. It is not
possible to trace only 2 out of 3 (or more) processes with the same name. You can enable one instance or all
instances (when multiple instances with the same process name exist and PID is not specified, all instances will
be enabled for tracing).

For example, this would trace all instances of App1.exe and App2.exe, but only the instance of App3.exe that
has a PID of 999:

``` syntax
App1.exe
App2.exe
App3.exe
     PID 999
```

Run the following command to start the tracing session:

**tracelog.exe -start \<sessionname> -guid #cfaa5446-c6c4-4f5c-866f-31c9b55b962d -f \<filename> -flag \<traceFlags>**

*sessionname* is the name given for the trace session. The
*guid* for the DCLocator tracing provider is
"cfaa5446-c6c4-4f5c-866f-31c9b55b962d". *filename* is the name of the
log file to which the events are written. *traceFlags* is one or more of the following
flags which signify which areas to trace:

| Flag | Hex Value | Description |
| --- | --- | --- |
| **DCLOCATOR_MISC** | 0x00000002 | Miscellaneous debugging |
| **DCLOCATOR_MAILSLOT** | 0x00000010 | Mailslot messages |
| **DCLOCATOR_SITE** | 0x00000020 | Sites |
| **DCLOCATOR_CRITICAL** | 0x00000100 | Important errors |
| **DCLOCATOR_SESSION_SETUP** | 0x00000200 | Trusted Domain Maintenance |
| **DCLOCATOR_DNS** | 0x00004000 | Name Registration |
| **DCLOCATOR_DNS_MORE** | 0x00020000 | Verbose Name Registration |
| **DCLOCATOR_MAILBOX_TEXT** | 0x02000000 | Verbose Mailbox Messages |
| **DCLOCATOR_SITE_MORE** | 0x08000000 | Verbose sites |

Run the following command to stop the trace session:

**tracelog.exe -stop \<sessionname>**

*sessionname* is the same name as the name you used when starting the session.

**Note** The registry key for the process being traced must be present in the registry at the time the trace session
is started. When the session starts, the process will verify whether or not it should be generating trace
messages (based on the presence or absence of a registry key for that process name and optional PID). The
process checks the registry only at the start of the session. Any changes in the registry occurring after that
will not have any effect on tracing.

> [!NOTE]
> The dsgetdc.h header defines DsGetDcName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DOMAIN_CONTROLLER_INFO](https://learn.microsoft.com/windows/desktop/api/dsgetdc/ns-dsgetdc-domain_controller_infoa)

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsGetSiteName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetsitenamea)

[DsValidateSubnetName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsvalidatesubnetnamea)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[Windows Time Service](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc773061(v=ws.10))