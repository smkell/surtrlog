{
    'variables': {
        'library%': 'static_library',
    },

    'targets': [
        {
            'target_name': 'surtrlog', 
            'type': '<(library)',

            'sources': [
                'src/logger.cc',
                'include/surtrlog/surtrlog.h',
                'include/surtrlog/version.h',
            ],

            'include_dirs': [
                'include',
            ],

            'direct_dependent_settings': {
                'include_dirs': [
                    'include'
                ]
            }
        }
    ]
}