#ifndef CWIZNOTEMANAGER_H
#define CWIZNOTEMANAGER_H

#include "wizdef.h"

/*
 * CWizNoteManager用于管理笔记相关的操作，例如创建、删除等。需要在程序启动时进行初始化
 */
class WIZDOCUMENTDATA;
class WIZTAGDATA;
class QNetworkAccessManager;
struct TemplateData;

#define WIZ_DOCUMENT_TYPE_NORMAL    "document"

class CWizNoteManager
{
public:
    CWizNoteManager(CWizDatabaseManager& dbMgr);

    //
    void createIntroductionNoteForNewRegisterAccount();
    // create note
    bool createNote(WIZDOCUMENTDATA& data);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID, const QString& strLocation);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID, const WIZTAGDATA& tag);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID, const QString& strLocation,
                    const WIZTAGDATA& tag);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID, const QString& strTitle,
                    const QString& strHtml);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID, const QString& strTitle,
                    const QString& strHtml, const QString& strLocation);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID, const QString& strTitle,
                    const QString& strHtml, const WIZTAGDATA& tag);
    bool createNote(WIZDOCUMENTDATA& data, const QString& strKbGUID, const QString& strTitle,
                    const QString& strHtml, const QString& strLocation, const WIZTAGDATA& tag);

    bool createNoteByTemplate(WIZDOCUMENTDATA& data, const WIZTAGDATA& tag, const QString& strZiw);

    void updateTemplateJS(const QString& local);
    void downloadTemplatePurchaseRecord();
    //
    static bool downloadTemplateBlocked(const TemplateData& tempData);

private:
    bool updateLocalTemplates(const QByteArray& newJsonData, QNetworkAccessManager& manager);

private:
    CWizDatabaseManager& m_dbMgr;
};

#endif // CWIZNOTEMANAGER_H
