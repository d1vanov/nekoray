#pragma once

#include <QJsonObject>
#include <QMap>
#include <QString>

#include <functional>
#include <memory>

namespace NekoGui_ConfigItem {
    // config tool
    enum itemType {
        string,
        integer,
        integer64,
        boolean,
        stringList,
        integerList,
        jsonStore,
    };

    class configItem {
    public:
        QString name;
        void *ptr;
        itemType type;

        configItem(QString n, void *p, itemType t) {
            name = std::move(n);
            ptr = p;
            type = t;
        }
    };

    // Formatable objects
    class JsonStore {
    public:
        QMap<QString, std::shared_ptr<configItem>> _map;

        std::function<void()> callback_after_load = nullptr;
        std::function<void()> callback_before_save = nullptr;

        QString fn;
        bool load_control_must = false; // must load from file
        bool save_control_compact = false;
        bool save_control_no_save = false;
        QByteArray last_save_content;

        JsonStore() = default;

        explicit JsonStore(QString fileName) {
            fn = std::move(fileName);
        }

        void _add(configItem *item);

        [[nodiscard]] QString _name(void *p);

        [[nodiscard]] std::shared_ptr<configItem> _get(const QString &name) const;

        void _setValue(const QString &name, void *p) const;

        [[nodiscard]] QJsonObject ToJson(const QStringList &without = {}) const;

        [[nodiscard]] QByteArray ToJsonBytes() const;

        void FromJson(QJsonObject object);

        void FromJsonBytes(const QByteArray &data);

        bool Save();

        bool Load();
    };
} // namespace NekoGui_ConfigItem

using namespace NekoGui_ConfigItem;
