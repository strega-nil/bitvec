project(
  'bitvec',
  'rust',
  version: '0.10.0',
  license: 'MIT',
  meson_version: '>=0.50.0',
)

# note: add rust_edition kw argument to project
bitvec_args = ['--edition=2018']

bitvec_std_enabled = not get_option('std').disabled()
bitvec_alloc_enabled = (
  (get_option('alloc').auto() and bitvec_std_enabled)
  or get_option('alloc').enabled()
)

if bitvec_std_enabled
  bitvec_args += ['--cfg', 'feature="std"']
endif
if bitvec_alloc_enabled
  bitvec_args += ['--cfg', 'feature="alloc"']
endif
if get_option('ffi').enabled()
  bitvec_args += ['--cfg', 'feature="ffi"']
endif

bitvec = library(
  'bitvec',
  'src/lib.rs',
  'src/bits.rs',
  'src/boxed.rs',
  'src/cursor.rs',
  'src/ffi.rs',
  'src/macros.rs',
  'src/pointer.rs',
  'src/slice.rs',
  'src/vec.rs',
  'src/ffi/boxed.rs',
  'src/ffi/slice.rs',
  'src/ffi/vec.rs',
  rust_args: bitvec_args,
)

bitvec_dep = declare_dependency(link_with: bitvec)
