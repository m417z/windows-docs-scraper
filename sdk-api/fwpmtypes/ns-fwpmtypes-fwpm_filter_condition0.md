# FWPM_FILTER_CONDITION0 structure

## Description

The **FWPM_FILTER_CONDITION0** structure expresses a filter condition that must be true for the action to be taken.

## Members

### `fieldKey`

GUID of the field to be tested. The available keys are listed under [Filtering Condition Identifiers](https://learn.microsoft.com/windows/win32/fwp/filtering-condition-identifiers-).

### `matchType`

A [FWP_MATCH_TYPE](https://docs.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_match_type) value that specifies the type of match to be performed.

### `conditionValue`

A [FWP_CONDITION_VALUE0](https://docs.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0) structure that contains the value to match the field against.

## Remarks

Field GUIDs are
only unique within a layer, so both the field GUID and the layer GUID are required to uniquely identify a
field.

The data type of

[FWP_MATCH_TYPE](https://docs.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_match_type) for detailed compatibility rules.

**FWPM_FILTER_CONDITION0** is a specific implementation of FWPM_FILTER_CONDITION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

#### Examples

The following C++ example shows how to initialize and add conditions to a filter.

```cpp
#include <windows.h>
#include <fwpmu.h>
#include <stdio.h>

#pragma comment(lib, "Fwpuclnt.lib")

// Some application to use for filter testing.
#define FILE0_PATH L"C:\\Program Files\\AppDirectory\\SomeApplication.exe"

void main()
{
    FWP_BYTE_BLOB *fwpApplicationByteBlob;
    FWPM_FILTER0 fwpFilter;
    FWPM_FILTER_CONDITION0 fwpConditions[4];
    int conCount = 0;
    DWORD result = ERROR_SUCCESS;

    fwpApplicationByteBlob = (FWP_BYTE_BLOB*) malloc(sizeof(FWP_BYTE_BLOB));

    printf("Retrieving application identifier for filter testing.\n");
    result = FwpmGetAppIdFromFileName0(FILE0_PATH, &fwpApplicationByteBlob);
    if (result != ERROR_SUCCESS)
    {
        printf("FwpmGetAppIdFromFileName failed (%d).\n", result);
        return;
    }

      // Application identifier filter condition.
      fwpConditions[conCount].fieldKey = FWPM_CONDITION_ALE_APP_ID;
      fwpConditions[conCount].matchType = FWP_MATCH_EQUAL;
      fwpConditions[conCount].conditionValue.type = FWP_BYTE_BLOB_TYPE;
      fwpConditions[conCount].conditionValue.byteBlob = fwpApplicationByteBlob;

      ++conCount;

      // TCP protocol filter condition
      fwpConditions[conCount].fieldKey = FWPM_CONDITION_IP_PROTOCOL;
      fwpConditions[conCount].matchType = FWP_MATCH_EQUAL;
      fwpConditions[conCount].conditionValue.type = FWP_UINT8;
      fwpConditions[conCount].conditionValue.uint8 = IPPROTO_TCP;

      ++conCount;

      // Add conditions and condition count to a filter.
      memset(&fwpFilter, 0, sizeof(FWPM_FILTER0));

      fwpFilter.numFilterConditions = conCount;
      if (conCount > 0)
        fwpFilter.filterCondition = fwpConditions;

      // Finish initializing filter...

    return;
}

```

## See also

[FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0)

[FWP_MATCH_TYPE](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_match_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)