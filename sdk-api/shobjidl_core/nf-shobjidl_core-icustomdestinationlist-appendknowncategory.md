# ICustomDestinationList::AppendKnownCategory

## Description

Specifies that the **Frequent** or **Recent** category should be included in a custom Jump List.

## Parameters

### `category` [in]

Type: **KNOWNDESTCATEGORY**

One of the following values that indicate which known category to add to the list:

#### KDC_FREQUENT (1)

1 - Add the **Frequent** category.

#### KDC_RECENT (2)

2 - Add the **Recent** category.

#### KDC_NONE (-1)

-1 - Do not use a category. Note, this value is not represented in KNOWNDESTCATEGORY, use `static_cast(-1)` to represent this.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

If there is a privacy Group Policy or user privacy setting present, it can affect the result of this method. Categories that contain user-specific items based on individual usage are not allowed under those privacy settings. Due to this, the **Recent** or **Frequent** categories added through this method will have no data, and categories with no data are not displayed. However, in that situation, this method call will not result in a failure code.

## Remarks

You must call [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) before you call this method.

The **Recent** category is shown in a default Jump List, but to show it in a custom Jump List together with custom categories you must explicitly request it through this method.

With both [AppendCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendcategory) and **AppendKnownCategory**, a custom Jump List should be designed to avoid any item appearing in more than one category. If two categories are simply different views on the same data, one of those categories should be removed since it is using Jump List space without contributing to the user's convenience. Duplicates are not hidden by the system except in the case of a pinned destination, in which case that destination is shown in the Pinned category and hidden in all others.

The **Frequent** and **Recent** categories are likely to contain a degree of overlap and therefore you should not add both categories to a single Jump List. Which of the two is best for your application depends on its nature. An application that generates files, such as Microsoft Word or Microsoft Paint, should use the **Recent** category as users are most likely to want to return to files that they have recently worked on. An application that is used more for browsing or playback of data created elsewhere should use the **Frequent** category because the user is more likely to access a greater number of items, many of them only once. In other words, if your application is most likely to access a large number of items only a few times each, which contributes noise to the smaller set of items users want to access many times, then **Frequent** is the best choice. If your application is more likely to access a smaller number of newer items most of the time, then you should choose **Recent**.

Categories in a custom Jump List, including the known **Recent** or **Frequent** category, are shown in the order that they are added, with the most recently added categories at the bottom of the list.

Any number of destinations added over the value pointed to by the *pcMinItems* parameter in [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) are not shown.

Empty categories are not shown.

The contents of the **Frequent** and **Recent** categories are calculated for each application that uses [SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs) directly. In some cases of user action, such as opening a file through Windows Explorer or using the common file dialog box to open, save, or create a file, the Shell calls **SHAddToRecentDocs** on behalf of an application and those calls are also taken into account in the usage statistics. The Shell also calls **SHAddToRecentDocs** on behalf of the application when a destination is launched from its Jump List. However, it is good practice for the application to explicitly call **SHAddToRecentDocs** itself even if it is expected that the Shell will make the call. This guarantees that the usage is recorded, and the algorithms for tracking recent or frequent usage will correct for any duplicate calls.

## See also

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[ICustomDestinationList::AddUserTasks](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-addusertasks)

[ICustomDestinationList::AppendCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendcategory)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)