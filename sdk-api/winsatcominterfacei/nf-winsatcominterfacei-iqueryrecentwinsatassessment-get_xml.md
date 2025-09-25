# IQueryRecentWinSATAssessment::get_XML

## Description

[IQueryRecentWinSATAssessment::XML may be altered or unavailable for releases after Windows 8.1.]

Retrieves data from the XML assessment document by using the specified XPath. The query is run against the most recent formal assessment in the WinSAT data store.

This property is read-only.

## Parameters

## Remarks

You can use this method to retrieve details of the assessment that are not available in the summary information provided through the API. For details about all the information available in an assessment, see the [WinSAT Schema](https://learn.microsoft.com/windows/desktop/WinSAT/winsat-schema).

The first formal assessment is run when you initially set up your computer. The initial assessment will remain in the data store for the life of the data store. The WinSAT data store can contain up to 100 formal assessments. When the store reaches capacity, WinSAT will delete the oldest assessment (but not the initial assessment) in the data store for each new formal assessment that is run.

The WinSAT data store contains only formal assessments. If you want to retrieve assessment data from ad hoc assessments, you must save the results to an XML file when you run the assessment (see the **-xml** command-line argument for details). You can then use the members of the **IXMLDOMDocument2** interface to query data from the ad hoc assessment.

To retrieve summary information about the assessment, call the [IQueryRecentWinSATAssessment::get_Info](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iqueryrecentwinsatassessment-get_info) method. To retrieve summary information for a subcomponent of the assessment, call the [IProvideWinSATResultsInfo::GetAssessmentInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-getassessmentinfo) method.

#### Examples

The following example shows how to use an XPath query to get data from the most recent formal assessment.

```cpp
#include <windows.h>
#include <stdio.h>
#include <winsatcominterfacei.h>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")

void main(void)
{
    HRESULT hr = S_OK;
    IQueryRecentWinSATAssessment* pAssessment;
    IXMLDOMNodeList* pNodes = NULL;
    IXMLDOMNode* pNode = NULL;
    long NodeCount = 0;
    BSTR bstrXPath = SysAllocString(L"WinSAT/TotalRunTime/Description");
    BSTR bstrTime = NULL;

    hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    // Get an instance to the most recent formal assessment.
    hr = CoCreateInstance(__uuidof(CQueryWinSAT),
        NULL,
        CLSCTX_INPROC_SERVER,
        __uuidof(IQueryRecentWinSATAssessment),
        (void**)&pAssessment);

    if (FAILED(hr))
    {
        wprintf(L"Failed to create an instance of IQueryRecentWinSATAssessment. Failed with 0x%x.\n", hr);
        goto cleanup;
    }

    // Query the assessment for the nodes that match the XPath expression.
    hr = pAssessment->get_XML(bstrXPath, NULL, &pNodes);
    if (FAILED(hr))
    {
        wprintf(L"pAssessment->get_XML failed with 0x%x.\n", hr);
        goto cleanup;
    }

    hr = pNodes->get_length(&NodeCount);
    wprintf(L"There were %d results found for the XPath query.\n\n", NodeCount);

    // Loop through the results.
    for (long i = 0; i < NodeCount; i++)
    {
        hr = pNodes->nextNode(&pNode);
        if (pNode)
        {
            hr = pNode->get_text(&bstrTime);
            if (S_OK == hr)
            {
                wprintf(L"Total runtime of the assessment: %s\n", bstrTime);
                SysFreeString(bstrTime);
            }
            else
            {
                wprintf(L"pNode->get_text failed with 0x%x.\n", hr);
                goto cleanup;
            }

            pNode->Release();
            pNode = NULL;
        }
        else
        {
            wprintf(L"pNodes->nextNode failed with 0x%x.\n", hr);
            goto cleanup;
        }
    }

cleanup:

    if (pAssessment)
        pAssessment->Release();

    if (pNodes)
        pNodes->Release();

    if (bstrXPath)
        SysFreeString(bstrXPath);

    CoUninitialize();
}

```

## See also

[IInitiateWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iinitiatewinsatassessment)

[IQueryAllWinSATAssessments::AllXML](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iqueryallwinsatassessments-get_allxml)

[IQueryRecentWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iqueryrecentwinsatassessment)