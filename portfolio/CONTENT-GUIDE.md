# Editing your portfolio

The website is designed so you can update it without changing the layout.

## Add or update written content

Open `script.js`. Near the top, the `portfolioData` section contains your skills, projects, achievements, certifications, and courses.

For example, add a course inside the `courses` list:

```js
courses: ['Introduction to Game Development'],
```

Add a certification inside the `certifications` list:

```js
certifications: ['Java Certification', 'Leadership Certification', 'New Certificate'],
```

## Replace your CV

Replace `assets/vansh-cv.pdf` with your new PDF. Keep the same filename so every View CV button continues to work.

## Add your profile photo

Put your photo in the `assets` folder and name it exactly:

`profile-photo.jpg`

The website will automatically show it instead of the “Add Profile Photo” placeholder.

## Update contact links

Open `index.html` and search for `vanshranasingh2006@gmail.com`, `github.com`, or `linkedin.com`. Replace the corresponding URL or email address.

## Publish changes

Commit and push your updated files. The public website is served from your `vanshranasingh2006-byte.github.io` repository.
