# APTTYPEQUALIFIER enumeration

## Description

Specifies the set of possible COM apartment type qualifiers.

## Constants

### `APTTYPEQUALIFIER_NONE:0`

No qualifier information for the current COM apartment type is available.

### `APTTYPEQUALIFIER_IMPLICIT_MTA:1`

This qualifier is only valid when the *pAptType* parameter of the [CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype) function specifies APTTYPE_MTA on return. A thread has an implicit MTA apartment type if it does not initialize the COM apartment itself, and if another thread has already initialized the MTA in the process. This qualifier informs the API caller that the MTA of the thread is implicitly inherited from other threads and is not initialized directly.

### `APTTYPEQUALIFIER_NA_ON_MTA:2`

This qualifier is only valid when the *pAptType* parameter of the [CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype) function contains APTTYPE_NA on return. When an MTA thread creates or invokes a COM in-process object using the "Neutral" threading model, the COM apartment type of the thread switches from MTA to a Neutral apartment type. This qualifier informs the API caller that the thread has switched from the MTA apartment type to the NA type.

### `APTTYPEQUALIFIER_NA_ON_STA:3`

This qualifier is only valid when the *pAptType* parameter of the [CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype) function contains APTTYPE_NA on return. When an STA thread creates or invokes a COM in-process object using the "Neutral" threading model, the COM apartment type of the thread switches from STA to a Neutral apartment type. This qualifier informs the API caller that the thread has switched from the STA apartment type to the NA type.

### `APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA:4`

This qualifier is only valid when the *pAptType* parameter of the [CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype) function contains APTTYPE_NA on return. When an implicit MTA thread creates or invokes a COM in-process object using the "Neutral" threading model, the COM apartment type of the thread switches from the implicit MTA type to a Neutral apartment type. This qualifier informs the API caller that the thread has switched from the implicit MTA apartment type to the NA type.

### `APTTYPEQUALIFIER_NA_ON_MAINSTA:5`

This qualifier is only valid when the *pAptType* parameter of the [CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype) function contains APTTYPE_NA on return. When the main STA thread creates or invokes a COM in-process object using the "Neutral" threading model, the COM apartment type of the thread switches from the main STA type to a Neutral apartment type. This qualifier informs the API caller that the thread has switched from the main STA apartment type to the NA type.

### `APTTYPEQUALIFIER_APPLICATION_STA:6`

### `APTTYPEQUALIFIER_RESERVED_1:7`

## See also

[CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype)