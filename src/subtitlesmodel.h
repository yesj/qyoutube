/*
 * Copyright (C) 2015 Stuart Howarth <showarth@marxoft.co.uk>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QYOUTUBE_SUBTITLESMODEL_H
#define QYOUTUBE_SUBTITLESMODEL_H

#include "model.h"
#include "subtitlesrequest.h"

namespace QYouTube {

class SubtitlesModelPrivate;

class QYOUTUBESHARED_EXPORT SubtitlesModel : public Model
{
    Q_OBJECT
    
    Q_PROPERTY(QYouTube::SubtitlesRequest::Status status READ status NOTIFY statusChanged)
    Q_PROPERTY(QVariant result READ result NOTIFY statusChanged)
    Q_PROPERTY(QYouTube::SubtitlesRequest::Error error READ error NOTIFY statusChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY statusChanged)
                
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        LanguageCodeRole,
        OriginalLanguageRole,
        TranslatedLanguageRole,
        UrlRole
    };
        
    explicit SubtitlesModel(QObject *parent = 0);
    
    SubtitlesRequest::Status status() const;
    
    QVariant result() const;
    
    SubtitlesRequest::Error error() const;
    QString errorString() const;
    
    void setNetworkAccessManager(QNetworkAccessManager *manager);
    
public Q_SLOTS:
    void list(const QString &id);
        
    void cancel();
    void reload();
    
Q_SIGNALS:
    void statusChanged(QYouTube::SubtitlesRequest::Status s);
    
private:        
    Q_DECLARE_PRIVATE(SubtitlesModel)
    Q_DISABLE_COPY(SubtitlesModel)
    
    Q_PRIVATE_SLOT(d_func(), void _q_onListRequestFinished())
};

}

#endif // QYOUTUBE_SUBTITLESMODEL_H
