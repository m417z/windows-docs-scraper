## Description

Values that are used in activation calls to indicate the execution contexts in which an object is to be run. These values are also used in calls to [CoRegisterClassObject](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coregisterclassobject) to indicate the set of execution contexts in which a class object is to be made available for requests to construct instances.

## Constants

### `CLSCTX_INPROC_SERVER:0x1`

The code that creates and manages objects of this class is a DLL that runs in the same process as the caller of the function specifying the class context.

### `CLSCTX_INPROC_HANDLER:0x2`

The code that manages objects of this class is an in-process handler. This is a DLL that runs in the client process and implements client-side structures of this class when instances of the class are accessed remotely.

### `CLSCTX_LOCAL_SERVER:0x4`

The EXE code that creates and manages objects of this class runs on same machine but is loaded in a separate process space.

### `CLSCTX_INPROC_SERVER16:0x8`

Obsolete.

### `CLSCTX_REMOTE_SERVER:0x10`

A remote context. The [LocalServer32](https://learn.microsoft.com/windows/win32/com/localserver32) or [LocalService](https://learn.microsoft.com/windows/win32/com/localservice) code that creates and manages objects of this class is run on a different computer.

### `CLSCTX_INPROC_HANDLER16:0x20`

Obsolete.

### `CLSCTX_RESERVED1:0x40`

Reserved.

### `CLSCTX_RESERVED2:0x80`

Reserved.

### `CLSCTX_RESERVED3:0x100`

Reserved.

### `CLSCTX_RESERVED4:0x200`

Reserved.

### `CLSCTX_NO_CODE_DOWNLOAD:0x400`

Disables the downloading of code from the directory service or the Internet. This flag cannot be set at the same time as CLSCTX_ENABLE_CODE_DOWNLOAD.

### `CLSCTX_RESERVED5:0x800`

Reserved.

### `CLSCTX_NO_CUSTOM_MARSHAL:0x1000`

Specify if you want the activation to fail if it uses custom marshalling.

### `CLSCTX_ENABLE_CODE_DOWNLOAD:0x2000`

Enables the downloading of code from the directory service or the Internet. This flag cannot be set at the same time as CLSCTX_NO_CODE_DOWNLOAD.

### `CLSCTX_NO_FAILURE_LOG:0x4000`

The CLSCTX_NO_FAILURE_LOG can be used to override the logging of failures in [CoCreateInstanceEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstanceex).

If the ActivationFailureLoggingLevel is created, the following values can determine the status of event logging:

* 0 = Discretionary logging. Log by default, but clients can override by specifying CLSCTX_NO_FAILURE_LOG in [CoCreateInstanceEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstanceex).
* 1 = Always log all failures no matter what the client specified.
* 2 = Never log any failures no matter what client specified. If the registry entry is missing, the default is 0. If you need to control customer applications, it is recommended that you set this value to 0 and write the client code to override failures. It is strongly recommended that you do not set the value to 2. If event logging is disabled, it is more difficult to diagnose problems.

### `CLSCTX_DISABLE_AAA:0x8000`

Disables activate-as-activator (AAA) activations for this activation only. This flag overrides the setting of the EOAC_DISABLE_AAA flag from the EOLE_AUTHENTICATION_CAPABILITIES enumeration. This flag cannot be set at the same time as CLSCTX_ENABLE_AAA. Any activation where a server process would be launched under the caller's identity is known as an activate-as-activator (AAA) activation. Disabling AAA activations allows an application that runs under a privileged account (such as LocalSystem) to help prevent its identity from being used to launch untrusted components. Library applications that use activation calls should always set this flag during those calls. This helps prevent the library application from being used in an escalation-of-privilege security attack. This is the only way to disable AAA activations in a library application because the EOAC_DISABLE_AAA flag from the EOLE_AUTHENTICATION_CAPABILITIES enumeration is applied only to the server process and not to the library application.

**Windows 2000:** This flag is not supported.

### `CLSCTX_ENABLE_AAA:0x10000`

Enables activate-as-activator (AAA) activations for this activation only. This flag overrides the setting of the EOAC_DISABLE_AAA flag from the EOLE_AUTHENTICATION_CAPABILITIES enumeration. This flag cannot be set at the same time as CLSCTX_DISABLE_AAA. Any activation where a server process would be launched under the caller's identity is known as an activate-as-activator (AAA) activation. Enabling this flag allows an application to transfer its identity to an activated component.

**Windows 2000:** This flag is not supported.

### `CLSCTX_FROM_DEFAULT_CONTEXT:0x20000`

Begin this activation from the default context of the current apartment.

### `CLSCTX_ACTIVATE_X86_SERVER:0x40000`

### `CLSCTX_ACTIVATE_32_BIT_SERVER`

Activate or connect to a 32-bit version of the server; fail if one is not registered.

### `CLSCTX_ACTIVATE_64_BIT_SERVER:0x80000`

Activate or connect to a 64 bit version of the server; fail if one is not registered.

### `CLSCTX_ENABLE_CLOAKING:0x100000`

When this flag is specified, COM uses the impersonation token of the thread, if one is present, for the activation request made by the thread. When this flag is not specified or if the thread does not have an impersonation token, COM uses the process token of the thread's process for the activation request made by the thread.

**Windows Vista or later:** This flag is supported.

### `CLSCTX_APPCONTAINER:0x400000`

Indicates activation is for an app container.

**Note** This flag is reserved for internal use and is not intended to be used directly from your code.

### `CLSCTX_ACTIVATE_AAA_AS_IU:0x800000`

Specify this flag for Interactive User activation behavior for As-Activator servers. A strongly named Medium IL Windows Store app can use this flag to launch an "As Activator" COM server without a strong name. Also, you can use this flag to bind to a running instance of the COM server that's launched by a desktop application.

The client must be Medium IL, it must be strongly named, which means that it has a SysAppID in the client token, it can't be in session 0, and it must have the same user as the session ID's user in the client token.

If the server is out-of-process and "As Activator", it launches the server with the token of the client token's session user. This token won't be strongly named.

If the server is out-of-process and RunAs "Interactive User", this flag has no effect.
If the server is out-of-process and is any other RunAs type, the activation fails.

This flag has no effect for in-process servers.

Off-machine activations fail when they use this flag.

### `CLSCTX_RESERVED6:0x1000000`

### `CLSCTX_ACTIVATE_ARM32_SERVER:0x2000000`

### `CLSCTX_PS_DLL:0x80000000`

Used for loading Proxy/Stub DLLs.

**Note** This flag is reserved for internal use and is not intended to be used directly from your code.

## Remarks

Values from the **CLSCTX** enumeration are used in activation calls ([CoCreateInstance](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance), [CoCreateInstanceEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstanceex), [CoGetClassObject](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cogetclassobject), and so on) to indicate the preferred execution contexts (in-process, local, or remote) in which an object is to be run. They are also used in calls to [CoRegisterClassObject](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coregisterclassobject) to indicate the set of execution contexts in which a class object is to be made available for requests to construct instances (**IClassFactory::CreateInstance**).

To indicate that more than one context is acceptable, you can combine multiple values with Boolean ORs. The contexts are tried in the order in which they are listed.

Given a set of **CLSCTX** flags, the execution context to be used depends on the availability of registered class codes and other parameters according to the following algorithm.

1. If the call specifies one of the following, CLSCTX_REMOTE_SERVER is implied and is added to the list of flags:
   1. An explicit [COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo) structure indicating a machine different from the current computer.
   2. No explicit [COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo) structure specified but the specified class is registered with either the [RemoteServerName](https://learn.microsoft.com/windows/win32/com/remoteservername) or [ActivateAtStorage](https://learn.microsoft.com/windows/win32/com/activateatstorage) registry value.The second case allows applications written prior to the release of distributed COM to be the configuration of classes for remote activation to be used by client applications available prior to DCOM and the CLSCTX_REMOTE_SERVER flag. The cases in which there would be no explicit [COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo) structure are when the value is specified as **NULL** or when it is not one of the function parameters (as in calls to [CoCreateInstance](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) and [CoGetClassObject](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cogetclassobject)).
2. If the explicit [COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo) parameter indicates the current computer, CLSCTX_REMOTE_SERVER is removed if present.

The rest of the processing proceeds by looking at the value(s) in the following sequence:

1. If the flags include CLSCTX_REMOTE_SERVER and no [COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo) parameter is specified and if the activation request indicates a persistent state from which to initialize the object (with [CoGetInstanceFromFile](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-cogetinstancefromfile), [CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-cogetinstancefromistorage), or, for a file moniker, in a call to [IMoniker::BindToObject](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-imoniker-bindtoobject)) and the class has an [ActivateAtStorage](https://learn.microsoft.com/windows/win32/com/activateatstorage) subkey or no class registry information whatsoever, the request to activate and initialize is forwarded to the computer where the persistent state resides. (Refer to the remote activation functions listed in the See Also section for details.)
2. If the flags include CLSCTX_INPROC_SERVER, the class code in the DLL found under the class's [InprocServer32](https://learn.microsoft.com/windows/win32/com/inprocserver32) key is used if this key exists. The class code will run within the same process as the caller.
3. If the flags include CLSCTX_INPROC_HANDLER, the class code in the DLL found under the class's [InprocHandler32](https://learn.microsoft.com/windows/win32/com/inprochandler32) key is used if this key exists. The class code will run within the same process as the caller.
4. If the flags include CLSCTX_LOCAL_SERVER, the class code in the service found under the class's [LocalService](https://learn.microsoft.com/windows/win32/com/localservice) key is used if this key exists. If no service is specified but an EXE is specified under that same key, the class code associated with that EXE is used. The class code (in either case) will be run in a separate service process on the same computer as the caller.
5. If the flag is set to CLSCTX_REMOTE_SERVER and an additional [COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo) parameter to the function specifies a particular remote computer, a request to activate is forwarded to this remote computer with flags modified to set to CLSCTX_LOCAL_SERVER. The class code will run in its own process on this specific computer, which must be different from that of the caller.
6. Finally, if the flags include CLSCTX_REMOTE_SERVER and no [COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo) parameter is specified and if a computer name is given under the class's [RemoteServerName](https://learn.microsoft.com/windows/win32/com/remoteservername) named-value, the request to activate is forwarded to this remote computer with the flags modified to be set to CLSCTX_LOCAL_SERVER. The class code will run in its own process on this specific computer, which must be different from that of the caller.

### CLSCTX_ACTIVATE_32_BIT_SERVER and CLSCTX_ACTIVATE_64_BIT_SERVER

The 64-bit versions of Windows introduce two new flags: CLSCTX_ACTIVATE_32_BIT_SERVER and CLSCTX_ACTIVATE_64_BIT_SERVER. On a 64-bit computer, a 32-bit and 64-bit version of the same COM server may coexist. When a client requests an activation of an out-of-process server, these **CLSCTX** flags allow the client to specify a 32-bit or a 64-bit version of the server.

Usually, a client will not care whether it uses a 32-bit or a 64-bit version of the server. However, if the server itself loads an additional in-process server, then it and the in-process server must both be either 32-bit or 64-bit. For example, suppose that the client wants to use a server "A", which in turn loads an in-process server "B". If only a 32-bit version of server "B" is available, then the client must specify the 32-bit version of server "A". If only a 64-bit version of server "B" is available, then the client must specify the 64-bit version of server "A".

A server can specify its own architecture preference via the [PreferredServerBitness](https://learn.microsoft.com/windows/win32/com/preferredserverbitness) registry key, but the client's preference, specified via a CLSCTX_ACTIVATE_32_BIT_SERVER or CLSCTX_ACTIVATE_64_BIT_SERVER flag, will override the server's preference. If the client does not specify a preference, then the server's preference will be used.

If neither the client nor the server specifies a preference, then:

* If the computer that hosts the server is running Windows Server 2003 with Service Pack 1 (SP1) or a later system, then COM will try to match the server architecture to the client architecture. In other words, for a 32-bit client, COM will activate a 32-bit server if available; otherwise it will activate a 64-bit version of the server. For a 64-bit client, COM will activate a 64-bit server if available; otherwise it will activate a 32-bit server.
* If the computer that hosts the server is running Windows XP or Windows Server 2003 without SP1 or later installed, then COM will prefer a 64-bit version of the server if available; otherwise it will activate a 32-bit version of the server.

If a **CLSCTX** enumeration has both the CLSCTX_ACTIVATE_32_BIT_SERVER and CLSCTX_ACTIVATE_64_BIT_SERVER flags set, then it is invalid and the activation will return E_INVALIDARG.

The following table shows the results of the various combinations of client architectures and client settings and server architectures and server settings.

The flags CLSCTX_ACTIVATE_32_BIT_SERVER and CLSCTX_ACTIVATE_64_BIT_SERVER flow across computer boundaries. If the computer that hosts the server is running the 64-bit Windows, then it will honor these flags; otherwise it will ignore them.

|  | 32-bit client, no flag | 64-bit client, no flag | 32-bit client, 32-bit flag¹ | 32-bit client, 64-bit flag² | 64-bit client, 32-bit flag¹ | 64-bit client, 64-bit flag² |
| --- | --- | --- | --- | --- | --- | --- |
| 32-bit server, match client registry value³ | 32-bit server | See ⁸ | 32-bit server | See ⁸ | 32-bit server | See ⁸ |
| 32-bit server, 32-bit registry value⁴ | 32-bit server | 32-bit server | 32-bit server | See ⁸ | 32-bit server | See ⁸ |
| 32-bit server, 64-bit registry value⁵ | See ⁸ | See ⁸ | 32-bit server | See ⁸ | 32-bit server | See ⁸ |
| 32-bit server, no registry value⁶ | 32-bit server | 64/32⁹ | 32-bit server | See ⁸ | 32-bit server | See ⁸ |
| 32-bit server, no registry value (before Windows Server 2003 with SP1)⁷ | 64/32⁹ | 64/32⁹ | 32-bit server | See ⁸ | 32-bit server | See ⁸ |
| 64-bit server, match client registry value³ | See ⁸ | 64-bit server | See ⁸ | 64-bit server | See ⁸ | 64-bit server |
| 64-bit server, 32-bit registry value⁴ | See ⁸ | See ⁸ | See ⁸ | 64-bit server | See ⁸ | 64-bit server |
| 64-bit server, 64-bit registry value⁵ | 64-bit server | 64-bit server | See ⁸ | 64-bit server | See ⁸ | 64-bit server |
| 64-bit server, no registry value⁶ | 32/64¹⁰ | 64-bit server | See ⁸ | 64-bit server | See ⁸ | 64-bit server |
| 64-bit server, no registry value (before Windows Server 2003 with SP1)⁷ | 64-bit server | 64-bit server | See ⁸ | 64-bit server | See ⁸ | 64-bit server |

## See also

[BIND_OPTS2](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts2~r1)

[COSERVERINFO](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-coserverinfo)

[CoCreateInstance](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance)

[CoCreateInstanceEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstanceex)

[CoGetClassObject](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cogetclassobject)

[CoGetInstanceFromFile](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-cogetinstancefromfile)

[CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-cogetinstancefromistorage)

[CoRegisterClassObject](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coregisterclassobject)

[Creating an Object Through a Class Object](https://learn.microsoft.com/windows/win32/com/creating-an-object-through-a-class-object)

[IClassActivator::GetClassObject](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-iclassactivator-getclassobject)

[Locating a Remote Object](https://learn.microsoft.com/windows/win32/com/locating-a-remote-object)

[Registering a Running EXE Server](https://learn.microsoft.com/windows/win32/com/registering-a-running-exe-server)