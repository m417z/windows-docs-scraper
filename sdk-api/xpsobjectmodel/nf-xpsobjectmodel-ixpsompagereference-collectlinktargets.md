# IXpsOMPageReference::CollectLinkTargets

## Description

Gets an [IXpsOMNameCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomnamecollection) interface that contains the names of all the document subtree objects whose **IsHyperlinkTarget** property is set to **TRUE**.

## Parameters

### `linkTargets` [out, retval]

A pointer to an [IXpsOMNameCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomnamecollection) interface that contains the names of all the document subtree objects whose **IsHyperlinkTarget** property is set to **TRUE**. If no such objects exist in the document, the **IXpsOMNameCollection** interface will be empty.

**Note** Every time this method is called, it returns a new collection.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | Not enough memory to perform this operation. |
| **E_POINTER** | *linkTargets* is **NULL**. |

## Remarks

If the page is originally loaded from a package but is not currently loaded in the object model, this method returns the values specified in the original **PageContent.LinkTargets** markup.

If the document does not have any link targets, the name collection returned in *linkTargets* will be empty.

To get the number of elements in the collection that is returned in *linkTargets*, call the collection's [GetCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomnamecollection-getcount) method.

This method returns the pointer to a new collection every time it is called. To prevent a memory leak, the pointer to a previous collection should be released when it is no longer needed or before the pointer variable is reused for another call to this method. The following code example shows how this can be done in a program.

```cpp
    HRESULT                         hr = S_OK;
    IXpsOMPage                      *page = NULL;
    IXpsOMNameCollection            *linkTargets = NULL;

    UINT32 numTargets = 0;
    UINT32 thisTarget = 0;
    LPWSTR thisTargetName = NULL;

    // pageRef contains the current page reference

    // if the page hasn't been loaded yet, for example, if the XPS OM
    //  was loaded from an XPS document, CollectLinkTargets obtains the
    //  list of link targets from the <PageContent.LinkTargets> markup
    hr = pageRef->CollectLinkTargets(&linkTargets);

    // get the page content of this page reference
    hr = pageRef->GetPage (&page);

    // after the page object has been loaded and calling GetPage or
    //  by creating a page in the XPS OM, CollectLinkTargets will now check
    //  each of the page elements to return the list so this call to
    //  CollectLinkTargets might take longer to return than the previous
    //  call above if the XPS OM was created from a file
    linkTargets->Release(); // release previous collection
    hr = pageRef->CollectLinkTargets(&linkTargets);

    // walk the list of link targets returned
    hr = linkTargets->GetCount( &numTargets );
    thisTarget = 0;
    while (thisTarget < numTargets) {
        hr = linkTargets->GetAt (thisTarget, &thisTargetName);
        printf ("%s\n", thisTargetName);
        // release the target string returned to prevent memory leaks
        CoTaskMemFree (thisTargetName);
        // get next target in list
        thisTarget++;
    }
    // release page and the link target collection
    page->Release();
    linkTargets->Release();

```

## See also

[IXpsOMNameCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomnamecollection)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)