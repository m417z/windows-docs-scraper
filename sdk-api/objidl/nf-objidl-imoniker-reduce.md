# IMoniker::Reduce

## Description

Reduces a moniker to its simplest form.

## Parameters

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context to be used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the moniker implementation should retrieve information about its environment.

### `dwReduceHowFar` [in]

Specifies how far this moniker should be reduced. This parameter must be one of the values from the [MKRREDUCE](https://learn.microsoft.com/windows/win32/api/objidl/ne-objidl-mkrreduce) enumeration.

### `ppmkToLeft` [in, out]

On entry, a pointer to an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that contains the interface pointer to moniker to the left of this moniker. This parameter is used primarily by moniker implementers to enable cooperation between the various components of a composite moniker; moniker clients can usually pass **NULL**.

On return, **ppmkToLeft* is usually set to **NULL**, indicating no change in the original moniker to the left. In rare situations, **ppmkToLeft* indicates a moniker, indicating that the previous moniker to the left should be disregarded and the moniker returned through **ppmkToLeft* is the replacement. In such a situation, the implementation must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the old moniker to the left of this moniker and must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the new returned moniker; the caller must release it later. If an error occurs, the implementation can either leave the interface pointer unchanged or set it to **NULL**.

### `ppmkReduced` [out]

A pointer to an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to the reduced form of this moniker, which can be **NULL** if an error occurs or if this moniker is reduced to nothing. If this moniker cannot be reduced, **ppmkReduced* is simply set to this moniker and the return value is MK_S_REDUCED_TO_SELF. If **ppmkReduced* is non-**NULL**, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the new moniker; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). (This is true even if **ppmkReduced* is set to this moniker.)

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **MK_S_REDUCED_TO_SELF** | This moniker could not be reduced any further, so *ppmkReduced* indicates this moniker. |
| **MK_E_EXCEEDEDDEADLINE** | The operation could not be completed within the time limit specified by the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure. |

## Remarks

This method is intended for the following uses:

* Enable the construction of user-defined macros or aliases as new kinds of moniker classes. When reduced, the moniker to which the macro evaluates is returned.
* Enable the construction of a kind of moniker that tracks data as it moves about. When reduced, the moniker of the data in its current location is returned.
* On file systems that support an identifier-based method of accessing files that is independent of filenames; a file moniker could be reduced to a moniker which contains one of these identifiers.

The intent of the [MKRREDUCE](https://learn.microsoft.com/windows/win32/api/objidl/ne-objidl-mkrreduce) flags passed in the *dwReduceHowFar* parameter is to provide the ability to programmatically reduce a moniker to a form whose display name is recognizable to the user. For example, paths in the file system, bookmarks in word-processing documents, and range names in spreadsheets are all recognizable to users. In contrast, a macro or an alias encapsulated in a moniker are not recognizable to users.

### Notes to Callers

The scenarios described above are not currently implemented by the system-supplied moniker classes.

You should call **Reduce** before comparing two monikers using the [IMoniker::IsEqual](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isequal) method because a reduced moniker is in its most specific form. **IsEqual** may return S_FALSE on two monikers before they are reduced and return S_OK after they are reduced.

### Notes to Implementers

If the current moniker can be reduced, your implementation must not reduce the moniker in-place. Instead, it must return a new moniker that represents the reduced state of the current one. This way, the caller still has the option of using the nonreduced moniker (for example, enumerating its components). Your implementation should reduce the moniker at least as far as is requested.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns MK_S_REDUCED_TO_SELF and passes back the same moniker. |
| Class moniker | This method returns MK_S_REDUCED_TO_SELF and passes back the same moniker. |
| File moniker | This method returns MK_S_REDUCED_TO_SELF and passes back the same moniker. |
| Generic composite moniker | This method recursively calls **Reduce** for each of its component monikers. If any of the components reduces itself, the method returns S_OK and passes back a composite of the reduced components. If no reduction occurred, the method passes back the same moniker and returns MK_S_REDUCED_TO_SELF. |
| Item moniker | This method returns MK_S_REDUCED_TO_SELF and passes back the same moniker. |
| OBJREF moniker | This method returns MK_S_REDUCED_TO_SELF and passes back the same moniker. |
| Pointer moniker | This method returns MK_S_REDUCED_TO_SELF and passes back the same moniker. |
| URL moniker | This method returns MK_S_REDUCED_TO_SELF and passes back the same moniker. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)