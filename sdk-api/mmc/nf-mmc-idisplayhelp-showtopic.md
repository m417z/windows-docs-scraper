# IDisplayHelp::ShowTopic

## Description

The **IDisplayHelp::ShowTopic** method displays the specified HTML Help topic in the merged MMC HTML Help file.

## Parameters

### `pszHelpTopic` [in]

A pointer to a **NULL**-terminated string specifying the topic to display in the merged MMC HTML Help file. The string must have the following format:

```cpp
helpfilename::topicfilename
```

where *helpfilename* is the file name of the snap-in's HTML Help file (.chm) that MMC merged into the MMC HTML Help collection file (this is the file name only, not the path to the original HTML Help file), and *topicfilename* is the internal path to the topic file within the snap-in's .chm file. The author of the snap-in's HTML Help file determines whether there is an internal directory structure for the topic HTML files or if all topic HTML files are at the root of the .chm file.

A snap-in tells MMC about its .chm file in its implementation of the
[ISnapinHelp2::GetHelpTopic](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814944(v=vs.85)) method.

For example, if the snap-in had the HTML Help file mysnapin.chm merged into the MMC HTML Help collection file, and a topic HTML file that had the internal file path of htm/help01.htm, the string would have the following form:

```cpp
mysnapin.chm::htm/help01.htm
```

If instead the help01.htm topic file is at the root of the mysnapin.chm Help file, the string should have the following form:

```cpp
mysnapin.chm::/help01.htm
```

Support for numeric IDs for topics is not included in versions 1.2 and earlier.

## Return value

This method can return one of these values.

## Remarks

MMC versions 1.0 and 1.1 required that *pszHelpTopic* be allocated with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and that MMC would then free the string. This violated the COM rules for allocation of in-parameters, which require that they be both allocated and freed by the caller (the snap-in). In MMC 1.2 and MMC 2.0, it is no longer required that *pszHelpTopic* be allocated with **CoTaskMemAlloc**. The caller is free to use whatever memory management it desires. If the caller chooses to use **CoTaskMemAlloc**, it is also responsible for calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the string.

A snap-in can provide context help for the selected item by handling the [MMCN_CONTEXTHELP](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-contexthelp) notification in its
[IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) method and calling **IDisplayHelp::ShowTopic**.

For property pages, the snap-in should call
[MMCPropertyHelp](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertyhelp) instead of **IDisplayHelp::ShowTopic**. Because an MMC property sheet is typically running on a separate thread, the property page cannot use the
[IDisplayHelp](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-idisplayhelp) interface directly. Instead, the property page can call
**MMCPropertyHelp** from the MMC library to achieve the same result.
**MMCPropertyHelp** takes the same topic string parameter as **IDisplayHelp::ShowTopic** and handles marshalling the request to the main MMC thread.

If the snap-in handles the [MMCN_CONTEXTHELP](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-contexthelp) notification, MMC expects the snap-in to specify a Help topic for the selected item. Consequently, in the notification handler for the **MMCN_CONTEXTHELP** notification, the snap-in has two options:

* It can call **IDisplayHelp::ShowTopic** or
  [MMCPropertyHelp](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertyhelp) to specify the Help topic and then return **S_OK** to indicate success. Be aware that the snap-in should only return **S_OK** if it specifies a Help topic. If the snap-in returns **S_OK** without specifying a Help topic, no Help topic will be displayed.
* It can return **S_FALSE** to the notification. MMC then displays the Help collection file with the default MMC topic selected.

## See also

[ISnapinHelp2::GetHelpTopic](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814944(v=vs.85))

[MMCPropertyHelp](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertyhelp)