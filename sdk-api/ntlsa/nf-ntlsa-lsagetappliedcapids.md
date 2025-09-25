# LsaGetAppliedCAPIDs function

## Description

The **LsaGetAppliedCAPIDs** function returns an array of central access policies (CAPs) identifiers (CAPIDs) of all the CAPs applied on a specific computer.

## Parameters

### `SystemName` [in, optional]

A pointer to an [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the specific computer. The name can have the form of "ComputerName" or "\\ComputerName". If this parameter is **NULL**, then the function returns the CAPIDs of the local computer.

### `CAPIDs` [out]

A pointer to a variable that receives an array of pointers to CAPIDs that identify the CAPs available on the specified computer. When you have finished using the CAPIDs, call the [LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory) function on each element in the array and the entire array.

### `CAPIDCount` [out]

A pointer to a variable that receives the number of CAPs that are available on the specified computer. The array returned in the *CAPIDs* parameter contains the same number of elements as the *CAPIDCount* parameter.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is one of the [LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values). You can use the [LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## Remarks

For specific details about the central access policies, you can query the attributes of the central access policy object in the Active Directory on the specified computer's domain controller. Look for the object whose **msAuthz-CentralAccessPolicyID** attribute matches one of the returned CAPIDs.

## See also

[Centralized Authorization Policy](https://learn.microsoft.com/windows/desktop/SecAuthZ/centralized-authorization-policy)