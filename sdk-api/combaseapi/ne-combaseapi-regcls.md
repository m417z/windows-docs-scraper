# REGCLS enumeration

## Description

Controls the type of connections to a class object.

## Constants

### `REGCLS_SINGLEUSE:0`

After an application is connected to a class object with [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject), the class object is removed from public view so that no other applications can connect to it. This value is commonly used for single document interface (SDI) applications. Specifying this value does not affect the responsibility of the object application to call [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject); it must always call **CoRevokeClassObject** when it is finished with an object class.

### `REGCLS_MULTIPLEUSE:1`

Multiple applications can connect to the class object through calls to [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject). If both the REGCLS_MULTIPLEUSE and CLSCTX_LOCAL_SERVER are set in a call to [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject), the class object is also automatically registered as an in-process server, whether CLSCTX_INPROC_SERVER is explicitly set.

### `REGCLS_MULTI_SEPARATE:2`

Useful for registering separate CLSCTX_LOCAL_SERVER and CLSCTX_INPROC_SERVER class factories through calls to [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject). If REGCLS_MULTI_SEPARATE is set, each execution context must be set separately; [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) does not automatically register an out-of-process server (for which CLSCTX_LOCAL_SERVER is set) as an in-process server. This allows the EXE to create multiple instances of the object for in-process needs, such as self embeddings, without disturbing its CLSCTX_LOCAL_SERVER registration. If an EXE registers a REGCLS_MULTI_SEPARATE class factory and a CLSCTX_INPROC_SERVER class factory, instance creation calls that specify CLSCTX_INPROC_SERVER in the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) parameter executed by the EXE would be satisfied locally without approaching the SCM. This mechanism is useful when the EXE uses functions such as [OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate) and [OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload) to create embeddings, but at the same does not wish to launch a new instance of itself for the self-embedding case. The distinction is important for embeddings because the default handler aggregates the proxy manager by default and the application should override this default behavior by calling [OleCreateEmbeddingHelper](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreateembeddinghelper) for the self-embedding case.

If your application need not distinguish between the local and inproc case, you need not register your class factory using REGCLS_MULTI_SEPARATE. In fact, the application incurs an extra network round trip to the SCM when it registers its MULTIPLEUSE class factory as MULTI_SEPARATE and does not register another class factory as INPROC_SERVER.

### `REGCLS_SUSPENDED:4`

Suspends registration and activation requests for the specified CLSID until there is a call to [CoResumeClassObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coresumeclassobjects). This is used typically to register the CLSIDs for servers that can register multiple class objects to reduce the overall registration time, and thus the server application startup time, by making a single call to the SCM, no matter how many CLSIDs are registered for the server.

**Note** This flag prevents COM activation errors from a possible race condition between an application shutting down and that application attempting to register a COM class.

### `REGCLS_SURROGATE:8`

The class object is a surrogate process used to run DLL servers. The class factory registered by the surrogate process is not the actual class factory implemented by the DLL server, but a generic class factory implemented by the surrogate. This generic class factory delegates instance creation and marshaling to the class factory of the DLL server running in the surrogate. For further information on DLL surrogates, see the [DllSurrogate](https://learn.microsoft.com/windows/desktop/com/dllsurrogate) registry value.

### `REGCLS_AGILE:0x10`

The class object aggregates the free-threaded marshaler
and will be made visible to all inproc apartments. Can be used together with other flags. For example, REGCLS_AGILE | REGCLS_MULTIPLEUSE to register a
class object that can be used multiple times from
different apartments. Without other flags, behavior
will retain REGCLS_SINGLEUSE semantics in that only
one instance can be generated.

## Remarks

In [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject), members of both the **REGCLS** and the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumerations, taken together, determine how the class object is registered.

An EXE surrogate (in which DLL servers are run) calls [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) to register a class factory using a new **REGCLS** value, REGCLS_SURROGATE.

All class factories for DLL surrogates should be registered with REGCLS_SURROGATE set. Do not set REGCLS_SINGLUSE or REGCLS_MULTIPLEUSE when you register a surrogate for DLL servers.

The following table summarizes the allowable **REGCLS** value combinations and the object registrations affected by the combinations.

|  | REGCLS_SINGLEUSE | REGCLS_MULTIPLEUSE | REGCLS_MULTI_SEPARATE | Other |
| --- | --- | --- | --- | --- |
| CLSCTX_INPROC_SERVER | Error | In-process | In-process | Error |
| CLSCTX_LOCAL_SERVER | Local | In-process/local | Local | Error |
| Both of the above | Error | In-process/local | In-process/local | Error |
| Other | Error | Error | Error | Error |

## See also

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject)

[DllGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllgetclassobject)

[DllSurrogate](https://learn.microsoft.com/windows/desktop/com/dllsurrogate)