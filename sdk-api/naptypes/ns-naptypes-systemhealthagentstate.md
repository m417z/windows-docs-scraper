# SystemHealthAgentState structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **SystemHealthAgentState** structure stores the dynamic state of the SHA.

## Members

### `id`

A unique [SystemHealthEntityId](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes) value that identifies the System Health Agent (SHA).

### `shaResultCodes`

A [ResultCodes](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-resultcodes) structure that contains the compliance result codes that were returned in the most recent [SoHRespnse](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) received from the SHA.

**Note** The [sohAttributeTypeComplianceResultCodes](https://learn.microsoft.com/windows/desktop/NAP/sohattributetype-enum) attribute type within the [SoHRespnse](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) contains the compliance result codes.

### `failureCategory`

A [FailureCategory](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory) value that describes the failure category fields that were returned in the most recent [SoHRespnse](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) received from the SHA.

**Note** The [sohAttributeTypeFailureCategory](https://learn.microsoft.com/windows/desktop/NAP/sohattributetype-enum) attribute type within the [SoHRespnse](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) contains the failure category fields.

### `fixupInfo`

A [FixupInfo](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-fixupinfo) structure that contains information about the fix-up state of the SHA.

## See also

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)