# IDebugHostSymbols::CreateTypeSignature

## Description

The CreateTypeSignature method creates a signature which can be used to match a set of concrete types by containing module and type name. The format of the type name signature string is specific to the language being debugged (and debug host). For C/C++, the signature string is equivalent to a NatVis Type Specification. That is, the signature string is a type name where wildcards (specified as *) are allowed for template arguments.

## Parameters

### `signatureSpecification`

The signature string which identifies the types to which this signature applies. The format of this string is specific to the language being debugged. For C/C++, this is equivalent to a NatVis type specification. Such is a type name where wildcards are allowed for template arguments (specified as a *).

### `module`

If specified, only types which are contained within the given module match the signature. If not specified, types in any module can potentially match the signature.

### `typeSignature`

The created type signature object is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHost> spHost; /* get the host */

ComPtr<IDebugHostSymbols> spSym;
if (SUCCEEDED(spHost.As(&spSym)))
{
    // Create a type signature for MyTemplateType<*>
    ComPtr<IDebugHostTypeSignature> spSig1;
    if (SUCCEEDED(spSym->CreateTypeSignature(L"MyTemplateType<*>",
                                             nullptr,
                                             &spSig1)))
    {
        // spSig1 is a type signature which will match any concrete template
        // type with a base name of MyTemplateType and *ANY* template arguments.
        // This is true regardless of the module in which the type is contained.
    }

    ComPtr<IDebugHostModule> spMyModule;
    if (SUCCEEDED(spSym->FindModuleByName(USE_CURRENT_HOST_CONTEXT,
                                          L"MyModule.dll",
                                          &spMyModule)))
    {
        // Create a type signature for MyTemplateType<*> within MyModule.dll.
        ComPtr<IDebugHostTypeSignature> spSig2;
        if (SUCCEEDED(spSym->CreateTypeSignature(L"MyTemplateType<*>",
                                                 nullptr,
                                                 &spSig2)))
        {
            // spSig2 is a type signature which will match any concrete
            // template type with a base name of MyTemplateType and *ANY*
            // template arguments that is within the particular MyModule.dll
            // that's in the current UI context (e.g.: process) of the debugger.
            // This means if the host is debugging multiple processes
            // and you switch processes, a MyTemplateType<*> in an identically
            // named and versioned MyModule.dll will *NOT* match this signature.
        }
    }
}
```

**Differences in symbol module matching in FindModuleByName, CreateTypeSignature and CreateTypeSignatureForModuleRange**

[FindModuleByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-findmodulebyname) will allow the passed module name to be either the module's real image name for example My Module.dll, or the one that you can reference it by in the debugger engine (e.g.: MyModule or MyModule_\<hex_base\>).

Calling [CreateTypeSignatureForModuleRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-createtypesignatureformodulerange) and passing a name/nullptr/nullptr will create a signature that will match any module that matches that name of any version.

The module name passed to the CreateTypeSignature functions will only accept the module's real image name (e.g.: MyModule.dll).

Calling [FindModuleByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-findmodulebyname) and then CreateTypeSignature with that module will create a signature that will match only the particular instance of the module passed to it. If there's two copies of a module that is loaded (e.g.: ntdll in a 32-bit process running on 64-bit Windows), it would only match the specific instance passed. It would also no longer match if that DLL were unloaded and reloaded. The signature is associated to a specific instance of a module as known by the debugger.

## See also

[IDebugHostSymbols interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbols)

[FindModuleByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-findmodulebyname)

[CreateTypeSignatureForModuleRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostsymbols-createtypesignatureformodulerange)