# IMetaDataImport::ResolveTypeRef

## Description

Resolves a Type reference represented by the specified TypeRef token.

## Parameters

### `tkTypeRef` [in]

The TypeRef metadata token to return the referenced type information for.

### `riid` [in]

The IID of the interface to return in ppIScope. Typically, this would be IID_IMetaDataImport.

### `ppIScope` [out]

An interface to the module scope in which the referenced type is defined.

### `ptkTypeDef` [out, retval]

A pointer to a TypeDef token that represents the referenced type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Important** Do not use this method if multiple application domains are loaded. The method does not respect application domain boundaries. If multiple versions of an assembly are loaded, and they contain the same type with the same namespace, the method returns the module scope of the first type it finds.

The **ResolveTypeRef** method searches for the type definition in other modules. If the type definition is found, **ResolveTypeRef** returns an interface to that module scope as well as the TypeDef token for the type.

If the type reference to be resolved has a resolution scope of AssemblyRef, the **ResolveTypeRef** method searches for a match only in the metadata scopes that have already been opened with calls to either the [IMetaDataDispenser::OpenScope](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadatadispenser-openscope) method or the [IMetaDataDispenser::OpenScopeOnMemory](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadatadispenser-openscopeonmemory) method. This is because **ResolveTypeRef** cannot determine from only the AssemblyRef scope where on disk or in the global assembly cache the assembly is stored.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)