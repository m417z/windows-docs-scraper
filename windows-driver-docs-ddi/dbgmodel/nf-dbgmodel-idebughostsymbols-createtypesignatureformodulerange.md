# IDebugHostSymbols::CreateTypeSignatureForModuleRange

## Description

The CreateTypeSignatureForModuleRange method creates a signature which can be used to match a set of concrete types by module signature and type name. This is similar to the CreateTypeSignature method excepting that instead of passing a specific module to match for the signature, the caller passes the arguments necessary to create a module signature (as if the module signature were created with the CreateModuleSignature method).

## Parameters

### `signatureSpecification`

The signature string which identifies the types to which this signature applies. The format of this string is specific to the language being debugged. For C/C++, this is equivalent to a NatVis type specification. Such is a type name where wildcards are allowed for template arguments (specified as a *).

### `moduleName`

The name that the containing module must match (case insensitive) in order for the type to be considered a match for the signature.

### `minVersion`

The minimum version of the containing module for the type to be considered a match for the signature. The format of this argument is equivalent to the same argument in CreateModuleSignature

### `maxVersion`

The maximum version of the containing module for the type to be considered a match for the signature. The format of this argument is equivalent to the same argument in CreateModuleSignature

### `typeSignature`

The newly created type signature object will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHost> spHost; /* get the host */

ComPtr<IDebugHostSymbols> spSym;
if (SUCCEEDED(spHost.As(&spSym)))
{
    ComPtr<IDebugHostTypeSignature> spSig;
    if (SUCCEEDED(spSym->CreateTypeSignatureForModuleRange(
        L"MyTemplateType<*>",
        L"MyModule.dll",
        L"6.3",
        L"10.0.0.0",
        &spSig)))
    {
        // spSig is a type signature which will match any template type with
        // a base name of MyTemplateType and *ANY* template arguments that is
        // within a module named "MyModule.dll" with a version >= 6.3(.0.0)
        // and a version <= 10.0.0.0 (regardless of the process/context of the module)
        //
        // Note that the version arguments are optional.  If absent, it indicates
        // there is either no lower or no upper bound on the module version
        // to match the signature.
    }
}
```

**Differences in symbol module matching in FindModuleByName, CreateTypeSignature and CreateTypeSignatureForModuleRange**

[FindModuleByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-findmodulebyname) will allow the passed module name to be either the module's real image name for example My Module.dll, or the one that you can reference it by in the debugger engine (e.g.: MyModule or MyModule_\<hex_base\>).

Calling CreateTypeSignatureForModuleRange and passing a name/nullptr/nullptr will create a signature that will match any module that matches that name of any version.

The module name passed to the CreateTypeSignature functions will only accept the module's real image name (e.g.: MyModule.dll).

Calling [FindModuleByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-findmodulebyname) and then [CreateTypeSignature](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-createtypesignature) with that module will create a signature that will match only the particular instance of the module passed to it. If there's two copies of a module that is loaded (e.g.: ntdll in a 32-bit process running on 64-bit Windows), it would only match the specific instance passed. It would also no longer match if that DLL were unloaded and reloaded. The signature is associated to a specific instance of a module as known by the debugger.

## See also

[IDebugHostSymbols interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbols)

[FindModuleByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-findmodulebyname)

[CreateTypeSignature](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-createtypesignature)